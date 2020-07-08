#include"interface.c"

int main(int argc, char* argv[]){
    printf("Welcome to \"Do\", your weekly agenda.\n");
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
                addTaskCase(w, 1); //infelizmente foi necessario encapsular a funcao addTask de "Week.c". O mesmo serve para demais funcoes com "Case" no fim
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
    return 0;
}