void main(){ 
   
// 声明变量
	int menu1,menu2;        //menu1:一级菜单 menu2:二级菜单 
	int i=0,n,dj_add[5]={ 
   0,0,0,0,0};
	struct StuLink *head=NULL,*pw;   //*head:学生信息链表头指针 pw:尾节点 
	
// 声明函数
// 从数据文件中逐行读取学生信息生成学生链表,返回头指针 
	struct StuLink *ReadFromFile();
// 先将学生链表按学号升序排序，再将学生链表中的数据逐行保存到数据文件
	void SaveToFile(struct StuLink *head);
// SortLink函数：按指定数据项的顺序【1:学号（升序）】或者【2:成绩（降序）】对学生链表进行排序 
	struct StuLink *SortLink(struct StuLink *head,int i); 
// InsertNode函数：在链表尾插入一个新结点。新结点的学号是链表中最大学号加1，姓名和成绩从键盘输入
// （注意：成绩必须在[0,100]区间的整数），根据成绩计算等级。
// 注意：插入结点会导致链表中各结点名次的变化。
	struct StuLink *InsertNode(struct StuLink *pw);
// EditNode函数：修改链表中指定学号的结点（学号不能修改，成绩必须在[0,100]区间的整数）
// 注意：当修改成绩时会导致等级和名次的变化
	void EditNode(struct StuLink *head); 
//DeleteNode函数：删除链表中指定学号的结点。注意：删除结点会导致链表中各结点名次的变化
	struct StuLink *DeleteNode(struct StuLink *head);
// QueryNode函数：查询链表中指定学号的结点，并显示查询结果。
void QueryNode(struct StuLink *head);
// QueryLink函数：查询链表中不及格的所有结点，并显示查询结果。
void QueryLink(struct StuLink *head);
//RankLink函数：计算链表中每个结点的名次。名次规则：按成绩降序排名，从第1名开始依次排名，
//若出现并列名次，则名次需要叠加。例如，若出现5个并列第1名，则没有第2名，下一个名次是第6名，依此类推。
void RankLink(struct StuLink *head);
//AnalysisLink函数：统计并返回各等级人数。等级标准：
//A：90及以上 B：80及以上 C：70及以上 D：60及以上 E：60以下
void AnalysisLink(struct StuLink *head,int *dj_add);
//OutputLink_1函数：按指定数据项的顺序【1:学号（升序）】或者【2:成绩（降序）】输出学生成绩表、各等级人数。
//学生成绩表每行输出一个学生信息（依次为学号、姓名、性别、成绩、等级和名次，各项间以1个空格隔开），
//各等级人数分行输出。
void  OutputLink_1(struct StuLink *head,int i);
//OutputLink_2函数：分页显示全部学生的信息。
//分页功能：每页显示10个学生信息，有上一页、下一页、首页和最后一页的翻页功能。
void  OutputLink_2(struct StuLink *head,int i);
	
// 执行语句
	head=ReadFromFile();     //读取文件到链表，获取头指针 
	
	
// 菜单
	while(1){ 
   
		system("cls");                  //清控制台，Windows 
		printf("========================================\n");//40个=
		printf("= =\n");
		printf("= 学生成绩管理程序 =\n");
		printf("= by：xxx =\n"); 
		printf("========================================\n");
		printf("= =\n");
		printf("= 1-数据维护 2-数据查询 =\n");
		printf("= 3-统计分析 4-报表输出 =\n");
		printf("= 0-退出 =\n");
		printf("= =\n");
		printf("========================================\n");
// printf("\n");
		printf("请选择：");
		scanf("%d",&menu1); 
		switch(menu1){ 
                    //一级菜单 
			case 1:
				while(1){ 
                         //循环输出二级菜单 
					system("cls");
					printf("\n");
					printf("========================================\n");
					printf("= =\n");
					printf("= 1-数据插入 2-数据修改 =\n");
					printf("= 3-数据删除 0-返回上级 =\n");
					printf("= =\n");
					printf("========================================\n");
					printf("请选择：");
					scanf("%d",&menu2); 
					switch(menu2){ 
         //二级菜单 
						case 1:
							printf("请输入要插入的学生个数(n>0): "); 
							scanf("%d",&n);
							while(n<=0){ 
   
								printf("！！！请输入正确的学生个数！！！： ");
								scanf("%d",&n);
							}
							pw=head;
							if(pw){ 
   
								while(pw->next)   //获取尾部节点 
									pw=pw->next;
							}
							
							for(i=0;i<n;i++){ 
   
								pw=InsertNode(pw);
								if(head==NULL) head=pw;
							}
							// 计算名次
							RankLink(head);
// SaveToFile(head); 
							break;
						case 2:
							EditNode(head);
							// 计算名次
							RankLink(head);
// SaveToFile(head);
							break;
						case 3:
							head=DeleteNode(head);
							// 计算名次
							RankLink(head);
// SaveToFile(head); 
							break;
						case 0:
							break;
					}
					if(menu2==0) break;
					}
				break;
			case 2:
				while(1){ 
                         //循环输出二级菜单 
					system("cls");
					printf("\n");
					printf("========================================\n");
					printf("= =\n");
					printf("=1-学号查询 2-不及格学生查询 0-返回上级=\n");
					printf("= =\n");
					printf("========================================\n");
					printf("请选择：");
					scanf("%d",&menu2); 
					switch(menu2){ 
         //二级菜单 
						case 1:
							QueryNode(head);
							printf("\n"); system("pause");
							break;
						case 2:
							QueryLink(head); 
							printf("\n"); system("pause");
							break;
						case 0:
							break;
					}
					if(menu2==0) break;
					}
				break;
			case 3:
				while(1){ 
                         //循环输出二级菜单 
					system("cls");
					printf("\n");
					printf("========================================\n");
					printf("= =\n");
					printf("= 1-成绩名次计算 2-成绩频次分析 =\n");
					printf("= 0-返回上级 =\n");
					printf("= =\n");
					printf("========================================\n");
					printf("请选择：");
					scanf("%d",&menu2); 
					switch(menu2){ 
         //二级菜单 
						case 1:
							RankLink(head);
							break;
						case 2:
							AnalysisLink(head,dj_add);
							printf("'A'有%d人；'B'有%d人，'C'有%d人，'D'有%d人，'E'有%d人，共有%d人\n",
							dj_add[0],dj_add[1],dj_add[2],dj_add[3],dj_add[4],dj_add[0]+dj_add[1]+dj_add[2]+dj_add[3]+dj_add[4]); 
							printf("\n"); system("pause"); 
							break;
						case 0:
							break;
					}
					if(menu2==0) break;
					}
				break;
			case 4:
				while(1){ 
                         //循环输出二级菜单 
					system("cls");
					printf("\n");
					printf("========================================\n");
					printf("= =\n");
					printf("=1-排序显示学生信息 2-分页显示学生信息=\n");
					printf("= 0-返回上级 =\n");
					printf("= =\n");
					printf("========================================\n");
					printf("请选择：");
					scanf("%d",&menu2); 
					switch(menu2){ 
         //二级菜单 
						case 1:
							printf("请选择按【1:学号（升序）】或者【2:成绩（降序）】输出学生成绩表：");
							scanf("%d",&i);
							while((i!=1)&&(i!=2)){ 
   
								printf("！！！请选择正确选项！！！1 or 2 ： ");
								scanf("%d",&i);
							}
							OutputLink_1(head,i);
							printf("\n"); 
							system("pause"); 
							break;
						case 2:
							printf("请选择按【1:学号（升序）】或者【2:成绩（降序）】输出学生成绩表：");
							scanf("%d",&i);
							while((i!=1)&&(i!=2)){ 
   
								printf("！！！请选择正确选项！！！1 or 2 ： ");
								scanf("%d",&i);
							}
							OutputLink_2(head,i);
							break;
						case 0:
							break;
					}
					if(menu2==0) break;
					}
				break;
			case 0:
				printf("========================================\n");
				printf("= =\n");
				printf("= 你已经退出学生管理系统 =\n");
				printf("= =\n");
				printf("========================================\n");
				return;       //退出main函数 
		}
	} 

} 