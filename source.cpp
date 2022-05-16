#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class cnodebooks{
public:
	int ISBN;
	int Num_of_books;
	float price;
	string name;
	cnodebooks* pnext;
};
class clistbooks{
public:
	cnodebooks* phead;
	cnodebooks* ptail;
	
	clistbooks()
	{
		phead=NULL;
		ptail=NULL;
	}
	void attach(cnodebooks* pnn){
		if(phead==NULL)
		{
			phead=pnn;
			ptail=pnn;
		}
		else{
			ptail->pnext=pnn;
			ptail=pnn;
		}
	}
	void dispall(){
		cnodebooks* ptrav=phead;
		while(ptrav!=NULL){
			cout<<ptrav->name<<endl;
			cout<<ptrav->ISBN<<endl;
			cout<<ptrav->price<<endl;
			cout<<ptrav->Num_of_books<<endl;
			ptrav=ptrav->pnext;
			cout<<endl;
		}
	}
	void remove(int id){
		cnodebooks* ptrav=phead, *pb=NULL;
		while(ptrav!=NULL){
			if(ptrav->ISBN==id){
				if(ptrav==phead){
					phead=ptrav->pnext;
					delete[] ptrav;
					break;
				}else if(ptrav!=phead && ptrav!=ptail){
					pb->pnext=ptrav->pnext;
					delete[] ptrav;
					break;
				}else{
					ptail=pb;
					ptail->pnext=NULL;
					delete[] ptrav;
					break;
				}
			}
			pb=ptrav;
			ptrav=ptrav->pnext;
		}
	}
};
void main(){
	fstream file;
	string line;
	file.open("smth.txt",ios::in);
	int i;
	clistbooks lib;
	while(getline(file,line))
	{


		i=0;
		cnodebooks* pnn;
		pnn=new cnodebooks[1];
		pnn->pnext=NULL;
		string name,isbn,no_of_books,price;
		while(line[i]!=',')
		{
			name+=line[i];
			i++;
		}
		i++;
		while(line[i]!=',')
		{
			isbn+=line[i];
			i++;
		}
		i++;
		while(line[i]!=',')
		{
			price+=line[i];
			i++;
		}
		i++;
		while(i<line.size())
		{
			no_of_books+=line[i];
			i++;
			
		}
		i++;
		pnn->name=name;
		pnn->ISBN=stoi(isbn);
		pnn->Num_of_books=stoi(no_of_books);
		pnn->price=stoi(price);
		lib.attach(pnn);
	}
	lib.dispall();
	file.close();
	cout<<"book you want to buy\n";
	int book_isbn;
	cnodebooks* ptrav=lib.phead;
	cin>>book_isbn;
	while(ptrav!=NULL)
	{
		if(ptrav->ISBN==book_isbn)
		{
			ptrav->Num_of_books-=1;
		}
		ptrav=ptrav->pnext;
	}
	cout<<endl;
	cout<<"After Modify\n";
	lib.dispall();

	fstream file2;
	file2.open("smth.txt");
	ptrav=lib.phead;
	while(ptrav!=NULL)
	{
		file2<<ptrav->name<<","<<ptrav->ISBN<<","<<ptrav->price<<","<<ptrav->Num_of_books<<endl;
		ptrav=ptrav->pnext;
	}
	file2.close();

	file2.open("smth.txt",ios::in|ios::out|ios::trunc);
	int Deleted_ISBN;
	cout<<"please enter the ISBN of the book you want to delete\n";
	cin>>Deleted_ISBN;

	lib.remove(Deleted_ISBN);
	cout<<"After Delete\n";
	lib.dispall();
	ptrav=lib.phead;
	while(ptrav!=NULL){
		if(file2.is_open()){
			file2<<ptrav->name<<","<<ptrav->ISBN<<","<<ptrav->price<<","<<ptrav->Num_of_books<<endl;
			ptrav=ptrav->pnext;
		}
	}
	file2.close();

	cout<<"append new book\n";
	int newISBN;
	cout<<"Please enter ISBN\n";
	cin>>newISBN;
	ptrav=lib.phead;
	int flag=0;
	while(ptrav!=NULL){
		if(newISBN==ptrav->ISBN){
			flag=1;
		}
		ptrav=ptrav->pnext;
	}
	string BookName;
	int NumberofBooks;
	float price;
	if(flag==0){
		cout<<"Please enter Book Name\n";
		cin>>BookName;
		cout<<"Please enter Number of Book\n";
		cin>>NumberofBooks;
		cout<<"Please enter Price of Book\n";
		cin>>price;
		cnodebooks*pnn=new cnodebooks;
		pnn->name=BookName;
		pnn->ISBN=newISBN;
		pnn->price=price;
		pnn->Num_of_books=NumberofBooks;
		pnn->pnext=NULL;
		lib.attach(pnn);
		file2.open("smth.txt",ios::in|ios::out|ios::app);
		file2<<BookName<<","<<newISBN<<","<<price<<","<<NumberofBooks<<endl;
		file2.close();
	}
	else{
		cout<<"this book already exists\n";
	}
	lib.dispall();
	system("pause");
}
