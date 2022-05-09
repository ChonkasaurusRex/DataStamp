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
	clistbooks(){
		phead=NULL;
		ptail=NULL;
	}
	void attach(cnodebooks* pnn){
		if(phead=NULL){
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
					delete ptrav;
					break;
				}else if(ptrav!=phead && ptrav!=ptail){
					pb->pnext=ptrav->pnext;
					delete ptrav;
					break;
				}else{
					ptail=pb;
					ptail->pnext=NULL;
					delete ptrav;
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
	while(getline(file,line)){
		i=0;
		cnodebooks* pnn;
		pnn=new cnodebooks[1];
		pnn->pnext=NULL;
		string name,isbn,no_of_books,price;
		while(line[i]!=','){
			name+=line[i];
			i++;
		}
		i++;
		while(line[i]!=','){
			isbn=+line[i];
			i++;
		}
		i++;
		while(line[i]!=','){
			no_of_books=+line[i];
			i++;
		}
		i++;
		while(line[i]!=','){
			price=+line[i];
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
	system("pause");
	file.close();
	
}