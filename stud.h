#ifndef stud_h
#define stud_h

#define NameSize 10
#define MajorSize 20

typedef struct _stud{
	int studNum;												//学生编号
	char studName[NameSize];									//学生姓名
	int studAge;												//学生年纪
	char studManjor[MajorSize];									//学生专业
} Stud;

void addStud();													//添加学生
void deleStud();												//删除学生
void editStud();												//编辑学生
void findStud();												//查找学生
void menuStud();												//学生菜单

#endif
