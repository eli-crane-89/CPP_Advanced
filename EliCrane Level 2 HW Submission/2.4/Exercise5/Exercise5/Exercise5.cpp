
#include <iostream>
#include <memory>
#include <stdio.h>


//Function Object
class FileFinalizer {
public:
	void operator() (FILE * f) {
		fclose(f);
		std::cout << "File has been released.\n";
	}
};

//Lambda
auto FileFinalizerLambda = [](FILE * f) -> void
{
	fclose(f);
	std::cout << "File has been released.\n"; };


//Free Function
void FileFinalizerFree(FILE * f) {
	fclose(f);
	std::cout << "File has been released.\n";
}

int main()
{

	//c)
	//Create scope for each pointer that points to test.txt


	//Delete with Functor
	{
		FILE* myFile;
		fopen_s(&myFile, "test1.txt", "w+");

		std::shared_ptr<FILE> mySharedFile(myFile, FileFinalizer());
	}

	//Delete with Lambda
	{
		FILE* myFile2;
		fopen_s(&myFile2, "test2.txt", "w+");

		std::shared_ptr<FILE> mySharedFile(myFile2, FileFinalizerLambda);
	}

	//Delete with Free Function
	{
		FILE* myFile3;
		fopen_s(&myFile3, "test3.txt", "w+");

		std::shared_ptr<FILE> mySharedFile(myFile3, FileFinalizerFree);
	}

	//d) Throw error

	//Need to scope it for file to be released automatically, even if with functor
	{
		FILE* myFile;
		myFile = fopen("test4.txt", "w"); //Removed Deprecated check on fopen
		std::shared_ptr<FILE> mySharedFile(myFile, FileFinalizer());

		for (int i = 0; i < 5; i++) {
			try {
				if (i == 4) {
					throw 10;
				}

				fprintf(myFile, "Some text %d\n", i);//, line);
			}
			catch (int e) {
				std::cout << "error thrown on iteration: " << i << std::endl;
			}
		}
	}
	std::cout << "record writing loop has finished." << std::endl;

	//Reopen file and try to write
	FILE* myFile2;
	myFile2 = fopen("test4.txt", "a+");
	fprintf(myFile2, "Some Final Text\n"); //If I don't initialize myFile as shared_ptr mySharedFile with the delete functor this line does not print to file
	fclose(myFile2);



    return 0;
}

