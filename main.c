#include"interface.c"
#include<iup/iup.h>
int main(int argc, char* argv[]){
    if(argc == 1){
        /*Testing IUP UI message window*/
        Ihandle *dlg, *label0, *label1, *label2, *label3, *vbox1, *vbox2, *vbox3, *hbox;
        IupOpen(&argc, &argv);
        label0 = IupLabel("Teste0");
        label1 = IupLabel("Teste1");
        label2 = IupLabel("Teste2");
        label3 = IupLabel("Teste3");
        vbox1 = IupVbox(label0, label1, NULL);
        vbox2 = IupVbox(label2, NULL);
        vbox3 = IupVbox(label3, NULL);
        hbox = IupHbox(vbox1, vbox2, vbox3, NULL);
        IupSetAttribute(hbox, "MARGIN", "10x10");
        IupSetAttribute(hbox, "GAP", "15");
        IupSetAttribute(hbox, "ALIGNMENT", "ACENTER");
        dlg = IupDialog(hbox);
        IupSetAttribute(dlg, "TITLE", "Do");
        IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
        IupMainLoop();
        IupClose();
    }else{
        printf("Welcome to \"Do\", your weekly schedule.\n");
        Week *w = readWeek();
        int status = 1;
        while(status){
            int op = -1;
            printf("What do you wish to do?\n");
            printf("[0] - Exit\n");
            printf("[1] - View all the tasks of the week\n");
            printf("[2] - View tasks on a certain day\n");
            printf("[3] - Create a new task\n");
            printf("[4] - Exclude the first task of a day\n");
            printf("[5] - Exclude the last task of a day\n");
            printf("[6] - Exclude a task of a day\n");
            printf("[7] - View a task on a certain day\n");
            printf("[8] - Search for and view a task on the week\n");
            printf("[9] - Swap two tasks between different days\n");
            printf("[10] - Swap all the tasks between different days\n");
            printf("[11] - Change a task's day\n");
            printf("[12] - Save changes\n");
            printf("Please type in an option: "); scanf("%d", &op);
            
            switch(op){
                case 0:
                    status = 0;
                    break;
                case 1:
                    prtWeek(w);
                    break;
                case 2:
                    prtDay(w, getDay());
                    break;
                case 3:
                    addTaskCase(w, 1);
                    break;
                case 4:
                    excTaskB(w, getDay(), 0);
                    break;
                case 5:
                    excTaskE(w, getDay(), 0);
                    break;
                case 6:
                    excTaskCase(w);
                    break;
                case 7:
                    prtTaskCase(w);
                    break;
                case 8:
                    prtWeekTasksCase(w);
                    break;
                case 9:
                    swpTasksCase(w);
                    break;
                case 10:
                    swpLists(w, getDay(), getDay());
                    break;
                case 11:
                    cngTaskDayCase(w);
                    break;
                case 12:
                    saveWeek(w);
                    break;
                default:
                    printf("Invalid option!\n");
                    getchar();
                    break;
            }
        }
    }
    return 0;
}