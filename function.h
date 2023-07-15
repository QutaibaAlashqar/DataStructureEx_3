

/// QUTAIBA ALASHQAR, 20290036.
/// LAB_3, DATA STRUCRUE;


int arr[200][2];
int position = 0;


struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};


struct nodeFB *insertFB(struct nodeFB **headfb, int idd, int agee){

    struct nodeFB *new_nodefb;
    new_nodefb = malloc(sizeof(struct nodeFB));
    new_nodefb-> id = idd;
    new_nodefb-> age = agee;
    new_nodefb-> next = (*headfb);
    (*headfb) = new_nodefb;
}


struct nodeFB *function_1(struct nodeFB *headfb){

    int number_1, number_2;
    struct nodeFB (*pointer), (*first) = 999999;
    pointer = headfb;

    while (pointer != NULL){
        first = pointer-> next;
        while (first != NULL){
            if (pointer->id > first->id){
                number_1 = pointer-> id;
                number_2 = pointer-> age;
                pointer-> id = first-> id;
                pointer-> age = first-> age;
                first-> id = number_1;
                first-> age = number_2;
            }
            /*
            if (ptr->id > first->id){
                number_2 = ptr-> age;
                ptr-> age = first-> age;
                first-> age = number_2;
            }
            */
            first = first-> next;
        }
        pointer = pointer-> next;
    }
}


struct nodeGS
{
	int id;
	struct nodeGS *next;
};


struct nodeGS *insertGS(struct nodeGS **headgs, int idd){

    struct nodeGS (*new_nodegs);
    new_nodegs = malloc(sizeof(struct nodeGS));
    new_nodegs-> id = idd;
    new_nodegs-> next = (*headgs);
    (*headgs) = new_nodegs;
}


struct nodeGS *function_2(struct nodeGS *headgs){

    int number;
    struct nodeGS (*pointer), (*last) = 0;
    pointer = headgs;

    while (pointer != NULL){
        last = pointer-> next;
        while (last != NULL){
            if (pointer->id < last->id){
                number = pointer-> id;
                pointer-> id = last-> id;
                last-> id = number;
            }
            last = last-> next;
        }
        pointer = pointer-> next;
    }
}


struct nodeFB *printFB(struct nodeFB *headfb){

    struct nodeFB (*pointer);
    pointer = headfb;

    function_1(headfb);

    while (pointer != NULL){
        printf("%d %d\n", pointer-> id, pointer-> age);
        pointer = pointer-> next;
    }
    printf("\n");
}


struct nodeGS *printGS(struct nodeGS *headgs){

    struct nodeGS (*pointer);
    pointer = headgs;

    function_2(headgs);

    while (pointer != NULL){
        printf("%d\n", pointer->id);
        pointer = pointer-> next;
    }
    printf("\n");
}


struct newNodeFB{

	int id;
	int age;
	struct newNodeGS *next;
};


struct newNodeGS{

	int id;
	struct newNodeFB *next;
};


struct newNodeFB *createFinalList(struct newNodeFB** startNewFB, struct nodeFB *startFB, struct nodeGS *startGS){

    struct newNodeFB (*pointer);
    struct nodeFB (*pointerFB);
    pointerFB = startFB;
    struct nodeGS (*pointerGS);
    pointerGS = startGS;

    while (pointerFB != NULL){

            pointer = malloc(sizeof(struct newNodeFB));
            pointer-> id = pointerFB-> id;
            pointer-> age = pointerFB-> age;
            pointer-> next = (*startNewFB);
            (*startNewFB) = pointer;
            pointerFB = pointerFB-> next;

            pointer = malloc(sizeof(struct newNodeFB));
            pointer-> id = pointerGS-> id;
            pointer-> age = -1;
            pointer-> next = (*startNewFB);
            (*startNewFB) = pointer;
            pointerGS = pointerGS-> next;
    }
}


struct newNodeFB *printAll(struct newNodeFB *startNewFB){

    struct newNodeFB (*point);
    point = startNewFB;
    while (point != NULL){

        arr[position][0] = point-> id;
        arr[position][1] = point-> age;
        point = point-> next;
        position++;
    }

    for (int new_pos = position - 1; new_pos >= 0; new_pos--){

        if (arr[new_pos][1] != -1){
            printf("%d %d\n", arr[new_pos][0], arr[new_pos][1]);
        }
        else{
            printf("%d\n", arr[new_pos][0]);
        }
    }
}

