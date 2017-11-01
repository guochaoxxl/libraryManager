#include <stdio.h>

#ifndef book_h
#define book_h

#define NameSize 20
#define ISBNSize 10
#define AuthorSize 10
#define PressSize 50

typedef struct _book{
	int bookNum;												//图书编号
	char bookName[NameSize];									//图书名称
	char bookISBN[ISBNSize];									//图书ISBN
	char bookAuthor[AuthorSize];								//图书作者
	char bookPress[PressSize];									//图书出版社
	float bookPrice;											//图书价格
	int bookStock;												//图书存量
} Book;

FILE *fopenC(char *);
FILE *fopenR(char *);
FILE *fopenW(char *);
void readBookInfo(char *, Book *);
void writeBookInfo(char *, Book *);
void outBookInfo(Book *);
void dispBookInfo(char *);

void addBook();													//添加图书
void deleBookByNum();											//删除图书
void editBook();												//编辑图书
Book *findBookByAuthor(char *, char*);							//查找图书
Book *findBookByNum(int , char*);								//查找图书
Book *findBookByISBN(char *, char*);							//查找图书
void menuBook();												//图书菜单

#endif
