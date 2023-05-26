#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct baza{
	int year_start, year_stop;
	int mounth_start, mounth_stop;
	int day_start, day_stop;
	int hours_start, hours_stop;
	int min_start, min_stop;
	char des[256];
} baza;

void input(baza *event, int num); // Ввод мероприятия
void output(baza *event, int num); // Вывод мероприятий
void outone(baza *event); // Вывод одного мероприятия

int del(baza *event, int num); // Удаление мероприятия

int insert(baza *event, int num); // Вставка мероприятия

int s_time_start(baza *a, baza *b);
void s_tStart(baza *event, int num); // Сортировка по времени начала

int s_time_stop(baza *a, baza *b);
void s_tStop(baza *event, int num); // Сортировка по времени окончания

int s_overlapping(baza *a, baza *b);
void s_Overlap(baza *event, int num); // Проверка на пересечение мероприятий

void s_free_interval(baza *event, int num); // Считает время между мероприятиями
int count_interval(baza *a, baza *b);

void saveStruct(baza *event, int num);
int loadStruct(baza *event, int num);

int main(){
	system("chcp 1251 > nul");
	
	baza event[25];
	int choose = 0, q = 0;
	char name[32];
		
	do {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Меню - работа с мероприятиями.\n1) Добавить мероприятие.\n2) Просмотреть текущие мероприятия.\n3) Сортировка по времени начала\n4)"
		" Сортировка по времени окончания\n5) Поиск перекрывающихся записей\n6) Поиск максимально незанятого промежутка времени"
		"\n7) Удаление мероприятия\n8) Вставка мероприятия\n9) Очистить список мероприятий\n"
		"10) Сохранить мероприятия\n11) Загрузить мероприятия\n0) Выход\nВыберите желаемое действие: ");
		while (1){
			fflush(stdin);
			scanf("%d", &choose);
			if (choose >= 0 && choose <= 11)
				break;
			else printf("\a\nВыберите действие от 0 до 11!\n");
				
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		switch(choose) {
			case 1:
				input(event, q);
				q++;
				break;
			case 2:
				output(event, q);
				break;
			case 3:
				s_tStart(event, q);
				printf("Сортировка успешно выполнена!\n\n");
				break;
			case 4:
				s_tStop(event, q);
				printf("Сортировка успешно выполнена!\n\n");
				break;
			case 5:
				s_Overlap(event, q);
				break;
			case 6:
				s_free_interval(event, q);
				break;
			case 7:
				q = del(event, q);
				break;
			case 8:
				q = insert(event, q);
				break;
			case 9:
				q = 0;
				printf("Мероприятия удалены!\n\n");
				break;
			case 10:
				saveStruct(event, q);
				break;
			case 11:
				q = loadStruct(event, q);
				break;
				
		}
	} while (choose != 0);
	
	return 0;
}

void input(baza *event, int num){
	if (num >= 25){
		printf("Не осталось места для нового мероприятия!\n\n");
		return;
	}
	
	while (printf("Введите дату начала мероприятия dd mm yyyy: "), fflush(stdin), 
	scanf("%d%d%d", &event[num].day_start, &event[num].mounth_start, &event[num].year_start), 
	event[num].day_start < 1 || event[num].day_start > 31 || event[num].mounth_start < 1 || 
	event[num].mounth_start > 12 || event[num].year_start < 2023 || event[num].year_start > 2100)
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
		
	while (1) {
		
		fflush(stdin); 
		printf("Введите дату конца мероприятия dd mm yyyy: ");
		scanf("%d%d%d", &event[num].day_stop, &event[num].mounth_stop, &event[num].year_stop);
		
		if (event[num].day_stop >= 1 || event[num].day_stop <= 31 || event[num].mounth_stop >= 1 
		|| event[num].mounth_stop <= 12 || event[num].year_stop >= 2023 || event[num].year_stop <= 2100
		|| event[num].year_stop >= event[num].year_start) {
			if (event[num].year_stop == event[num].year_start) {
				if (event[num].mounth_stop == event[num].mounth_start) {
					if (event[num].day_stop >= event[num].day_start) 
						break;
					else
						printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				}
				else {
					if (event[num].mounth_stop > event[num].mounth_start) 
						break;
					else 
						printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				}
			}
			else {
				if (event[num].year_stop < event[num].year_start)
					printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				else
					break;
			}
		}
	}
	
	while (printf("Введите время начала мероприятия hh mm: "), fflush(stdin), 
	scanf("%d%d", &event[num].hours_start, &event[num].min_start),
	event[num].hours_start < 0 || event[num].hours_start > 23 || event[num].min_start < 0 || 
	event[num].min_start > 59)
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
	
	while (printf("Введите время окончания мероприятия hh mm: "), fflush(stdin), 
	scanf("%d%d", &event[num].hours_stop, &event[num].min_stop),
	(event[num].hours_stop < 0 || event[num].hours_stop > 23 || event[num].min_stop < 0 || 
	event[num].min_stop > 59) || (event[num].hours_stop == event[num].hours_start && 
	event[num].min_stop <= event[num].min_start) && (event[num].year_start == event[num].year_stop &&
	event[num].mounth_start == event[num].mounth_stop && event[num].day_start == event[num].day_stop)
	|| (event[num].hours_stop < event[num].hours_start) && (event[num].year_start == event[num].year_stop &&
	event[num].mounth_start == event[num].mounth_stop && event[num].day_start == event[num].day_stop))
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\nМероприятие не может закончится раньше чем началось!\n");
	
	printf("Введите описание для мероприятия: ");
	fflush(stdin);
	gets(event[num].des);
	fflush(stdin);
	printf("\n\n");
}

void output(baza *event, int num){
	if (num == 0){
		printf("Нечего выводить\n\n");
		return;
	}
	int i, c = 1;
	for (i = 0; i != num; i++){
		printf("№%d\nДата мероприятия - %02d.%02d.%d - %02d.%02d.%d\n", c, event[i].day_start, 
		event[i].mounth_start, event[i].year_start, event[i].day_stop, event[i].mounth_stop,
		event[i].year_stop);
	
		printf("Время мероприятия: %02d:%02d - %02d:%02d\n", event[i].hours_start, event[i].min_start, 
		event[i].hours_stop, event[i].min_stop);
	
		printf("Описание: %s\n\n", event[i].des);
		
		c++;
	}	
}

void outone(baza *event){
	printf("\nДата мероприятия - %02d.%02d.%d - %02d.%02d.%d\n", event->day_start, 
	event->mounth_start, event->year_start, event->day_stop, event->mounth_stop,
	event->year_stop);
	
	printf("Время мероприятия: %02d:%02d - %02d:%02d\n", event->hours_start, event->min_start, 
	event->hours_stop, event->min_stop);
	
	printf("Описание: %s\n\n", event->des);
}

int del(baza *event, int num) {
	int i;
	while (printf("Введите номер мероприятия который вы хотите удалить - "), fflush(stdin), scanf("%d", &i),
	i <= 0 || i > num)
		printf("Несуществующий номер мероприятия!\n\n");
	for(i; i != num; i++){
		event[i-1] = event[i];
	}
	return i - 1;
}

int insert(baza *event, int num){
	int i, k;
	while (printf("Введите после какого мероприятия вы хотите вставить новое мероприятие - "), fflush(stdin), scanf("%d", &i),
	i < 0 || i > num)
		printf("Несуществующий номер мероприятия!\n\n");
	for(k = num; k > i; k--){
		event[k] = event[k-1];
	}
	input(event, i);

	return num + 1;
}

int s_time_start(baza *a, baza *b){
	if (a->year_start > b->year_start) return 1;
	if (a->year_start < b->year_start) return 0;
	else {
		if (a->mounth_start > b->mounth_start) return 1;
		if (a->mounth_start < b->mounth_start) return 0;
		else{
			if (a->day_start > b->day_start) return 1;
			if (a->day_start < b->day_start) return 0;
			else{
				if(a->hours_start > b->hours_start) return 1;
				if(a->hours_start < b->hours_start) return 0;
				else{
					if (a->min_start > b->min_start) return 1;
					else return 0;
				}
			}
		}
	}						
}

void s_tStart(baza *event, int num){
	baza t;
	int i, check = 0;
	while (check == 0) {
		for (i = 0, check = 1; i < num-1; i++){
			if (s_time_start(event+i, event+i+1)){
				t = event[i];
				event[i] = event[i+1];
				event[i+1] = t;
				check = 0;
			}
		}
	}
}

int s_time_stop(baza *a, baza *b){
	if (a->year_stop > b->year_stop) return 1;
	if (a->year_stop < b->year_stop) return 0;
	else {
		if (a->mounth_stop > b->mounth_stop) return 1;
		if (a->mounth_stop < b->mounth_stop) return 0;
		else{
			if (a->day_stop > b->day_stop) return 1;
			if (a->day_stop < b->day_stop) return 0;
			else{
				if(a->hours_stop > b->hours_stop) return 1;
				if(a->hours_stop < b->hours_stop) return 0;
				else{
					if (a->min_stop > b->min_stop) return 1;
					else return 0;
				}
			}
		}
	}						
}

void s_tStop(baza *event, int num){
	baza t;
	int i, check = 0;
	while (check == 0) {
		for (i = 0, check = 1; i < num-1; i++){
			if (s_time_stop(event+i, event+i+1)){
				t = event[i];
				event[i] = event[i+1];
				event[i+1] = t;
				check = 0;
			}
		}
	}
}

int s_overlapping(baza *a, baza *b){
	if (a->year_stop > b->year_start) return 1;
	if (a->year_stop < b->year_start) return 0;
	else {
		if (a->mounth_stop > b->mounth_start) return 1;
		if (a->mounth_stop < b->mounth_start) return 0;
		else{
			if (a->day_stop > b->day_start) return 1;
			if (a->day_stop < b->day_start) return 0;
			else{
				if(a->hours_stop > b->hours_start) return 1;
				if(a->hours_stop < b->hours_start) return 0;
				else{
					if (a->min_stop > b->min_start) return 1;
					else return 0;
				}
			}
		}
	}						
}

void s_Overlap(baza *event, int num){
	int i = 0, k = 0, numer = 1;
	s_tStop(event, num);
	for (k = 0; k < num-1; k++){
		for (i = k+1; i < num; i++){
			if (s_overlapping(event+k, event+i)){
				printf("№%d   Пересекаются мероприятия", numer);
				outone(event+k);
				outone(event+i);
				printf("||||||||||||||||||||||||||||||||||\n");
				numer++;
			}
		}
	}
}

int count_interval(baza *a, baza *b){
	int min1 = 0, min2 = 0, h1= 0, h2 = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	int total = 0;
	int mounth[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int i = 0, days = 0;
	
	m1 = a->mounth_stop - 1;
	m2 = b->mounth_start - 1;
	
	y1 = a->year_stop - 1;
	y2 = b->year_start - 1;
	
	min1 = a->min_stop * 60;
	min2 = b->min_start * 60;
	
	h1 = a->hours_stop * 60 * 60;
	h2 = b->hours_start * 60 * 60;
	
	d1 = a->day_stop;
	d2 = b->day_start;
	
	if (a->year_stop % 4 == 0 || (a->year_stop % 100 == 0) && (a->year_stop % 400 == 0)){
		if (m1 > 2) {
			m1 = mounth[m1] + 1;
		}
		else m1 = mounth[m1];
	}
	else m1 = mounth[m1];
	
	if (b->year_start % 4 == 0 || (b->year_start % 100 == 0) && (b->year_start % 400 == 0)){
		if (m2 > 2) {
			m2 = mounth[m2] + 1;
		}
		else m2 = mounth[m2];
	}
	else m2 = mounth[m2];
	
	
	y1 = (y1 * 365) + ((y1 / 4) - (y1 / 100) + (y1 / 400));
	y2 = (y2 * 365) + ((y2 / 4) - (y2 / 100) + (y2 / 400));
	
	days = (y2 + m2 + d2) - (y1 + m1 + d1);
	total = abs(days * 24 * 3600 + h2 + min2) - (h1 + min1);
	
	return total;
}

void s_free_interval(baza *event, int num){
	int max = 0, i = 0, time = 0;
	s_tStart(event, num);
	for (i = 0; i < num-1; i++){
		if (s_overlapping(event+i, event+i+1) == 0){
			time = count_interval(event+i, event+i+1);
			outone(event+i);
			printf("Временной промежуток между мероприятиями равен -> %d\n", time);
			outone(event+i+1);
			printf("||||||||||||||||||||||||||||||||||\n");
		}
		if (time > max) max = time;
	}
	printf("Максимальный промежуток незанятого времени равен -> %d\n", max);
}

void saveStruct(baza *event, int num){
	char name[32];
	int i;
	FILE *fl;
	
	printf("Введите имя файла: ");
	fflush(stdin);
	scanf("%s", name);
	strcat(name, ".txt");
	
	fl = fopen(name, "w");
	if (fl != NULL){
		for(i = 0; i < num; i++){
			fprintf(fl, "%02d %02d %d", event[i].day_start, event[i].mounth_start, event[i].year_start);
			fprintf(fl, " %02d %02d\n", event[i].hours_start, event[i].min_start);
			
			fprintf(fl, "%02d %02d %d", event[i].day_stop, event[i].mounth_stop, event[i].year_stop);
			fprintf(fl, " %02d %02d\n", event[i].hours_stop, event[i].min_stop);
			
			fprintf(fl, "%s\n\n", event[i].des);
		}
	}
	else printf("EROR 404");
	fclose(fl);
}

int loadStruct(baza *event, int num){
	int i;
	char name[32], *p;
	FILE *fl;
	printf("Введите имя файла для загрузки: ");
	fflush(stdin);
	scanf("%s", name);
	strcat(name, ".txt");
	fl = fopen(name, "r");
	if (fl == NULL){
		printf("Данного файла не существует!\n");
		return num;
	}
	for(i = 0; i < 25; i++){
		if (fscanf(fl, "%d%d%d", &event[i].day_start, &event[i].mounth_start, &event[i].year_start) != 3) break;
		if (fscanf(fl, "%d%d\n", &event[i].hours_start, &event[i].min_start) != 2) break;
		
		if (fscanf(fl, "%d%d%d", &event[i].day_stop, &event[i].mounth_stop, &event[i].year_stop) != 3) break;
		if (fscanf(fl, "%d%d\n", &event[i].hours_stop, &event[i].min_stop) != 2) break;
		
		fgets(event[i].des, 256, fl);
		p = strchr(event[i].des, '\n');
		if(p != NULL) *p = 0;
	}
	fclose(fl);
	return i;
}
