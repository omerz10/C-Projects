/******************************************
* Student name: Omer Zucker
* Student: 200876548
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#ifndef GADT_H
#define GADT_H
#define MAX_STR 16

//typedef declaration
typedef void* ELM;
typedef void* HEAD;
typedef enum { success, outOfMem, badArgs, failure } RESULT;
HEAD SLCreate(ELM head_val, ELM(*create_elm)(), void(*cpy_elm)(ELM, ELM),
	int(*cmp_elm)(ELM, ELM), void(*free_elm)(ELM),
	void(*print_elm)(ELM), ELM(*add_elm_to_elm)(ELM, ELM));
void SLDestroy(HEAD head);
RESULT SLAddListElement(HEAD* head, ELM node);
RESULT SLRemoveElement(HEAD* head, ELM node);
ELM SLFindElement(HEAD head, ELM node);
void SLAddToElement(HEAD* head, ELM toEl, ELM addEl);
void SLPrintList(HEAD head);

#endif
