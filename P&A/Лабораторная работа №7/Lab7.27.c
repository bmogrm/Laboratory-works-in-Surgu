#include <stdio.h>
#include <stdlib.h>


typedef struct baza{
	int year_start, year_stop;
	int mounth_start, mounth_stop;
	int day_start, day_stop;
	int hours_start, hours_stop;
	int min_start, min_stop;
	char des[256];
} baza;

void input(baza *event);
void output(baza *event);

char s_time_start(baza *event1, baza *event2);
void s_tStart(baza *event1, baza *event2);

char s_time_stop(baza *event1, baza *event2);
void s_tStop(baza *event1, baza *event2);

char s_overlapping(baza *event1, baza *event2);
char s_Overlap(baza *event1, baza *event2);
void s_totalOverlap(baza *event1, baza *event2);

void s_free_interval(baza *event1, baza *event2);
void count_interval(baza *event1, baza *event2);

int main(){
	system("chcp 1251 > nul");
	
	baza event1, event2;
	int choose = 0;
	
	do {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Меню - работа с мероприятиями.\n1) Добавить мероприятие.\n2) Просмотреть текущие мероприятия.\n3) Сортировка по времени начала\n4)"
		" Сортировка по времени окончания\n5) Поиск перекрывающихся записей\n6) Поиск максимально незанятого промежутка времени\n0) Выход\nВыберите желаемое действие: ");
		while (1){
			fflush(stdin);
			scanf("%d", &choose);
			if (choose >= 0 && choose < 7)
				break;
			else printf("\a\nВыберите действие от 0 до 6!\n");
				
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		switch(choose) {
			case 1:
				input(&event1);
				input(&event2);
				break;
			case 2:
				output(&event1);
				output(&event2);
				break;
			case 3:
				s_tStart(&event1, &event2);
				break;
			case 4:
				s_tStop(&event1, &event2);
				break;
			case 5:
				s_totalOverlap(&event1, &event2);
				break;
			case 6:
				s_free_interval(&event1, &event2);
				break;
		}
	} while (choose != 0);
	
	return 0;
}

void input(baza *event){
	while (printf("Введите дату начала мероприятия dd mm yyyy: "), fflush(stdin), 
	scanf("%d%d%d", &event->day_start, &event->mounth_start, &event->year_start), 
	event->day_start < 1 || event->day_start > 31 || event->mounth_start < 1 || 
	event->mounth_start > 12 || event->year_start < 2023 || event->year_start > 2100)
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
		
	while (1) {
		
		fflush(stdin); 
		printf("Введите дату конца мероприятия dd mm yyyy: ");
		scanf("%d%d%d", &event->day_stop, &event->mounth_stop, &event->year_stop);
		
		if (event->day_stop >= 1 || event->day_stop <= 31 || event->mounth_stop >= 1 
		|| event->mounth_stop <= 12 || event->year_stop >= 2023 || event->year_stop <= 2100
		|| event->year_stop >= event->year_start) {
			if (event->year_stop == event->year_start) {
				if (event->mounth_stop == event->mounth_start) {
					if (event->day_stop >= event->day_start) 
						break;
					else
						printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				}
				else {
					if (event->mounth_stop > event->mounth_start) 
						break;
					else 
						printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				}
			}
			else {
				if (event->year_stop < event->year_start)
					printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
				else
					break;
			}
		}
	}
	
	while (printf("Введите время начала мероприятия hh mm: "), fflush(stdin), 
	scanf("%d%d", &event->hours_start, &event->min_start),
	event->hours_start < 0 || event->hours_start > 23 || event->min_start < 0 || 
	event->min_start > 59)
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\n");
	
	while (printf("Введите время окончания мероприятия hh mm: "), fflush(stdin), 
	scanf("%d%d", &event->hours_stop, &event->min_stop),
	(event->hours_stop < 0 || event->hours_stop > 23 || event->min_stop < 0 || 
	event->min_stop > 59) || (event->hours_stop == event->hours_start && 
	event->min_stop <= event->min_start) && (event->year_start == event->year_stop &&
	event->mounth_start == event->mounth_stop && event->day_start == event->day_stop)
	|| (event->hours_stop < event->hours_start) && (event->year_start == event->year_stop &&
	event->mounth_start == event->mounth_stop && event->day_start == event->day_stop))
	
		printf("\a\nВведите дату согласно указанному шаблону и логике!\nМероприятие не может закончится раньше чем началось!\n");
	
	printf("Введите описание для мероприятия: ");
	fflush(stdin);
	gets(event->des);
	fflush(stdin);
	printf("\n\n");
}

void output(baza *event){
		
	printf("Дата мероприятия - %02d.%02d.%d - %02d.%02d.%d\n", event->day_start, 
	event->mounth_start, event->year_start, event->day_stop, event->mounth_stop,
	event->year_stop);
	
	printf("Время мероприятия: %02d:%02d - %02d:%02d\n", event->hours_start, event->min_start, 
	event->hours_stop, event->min_stop);
	
	printf("Описание: %s\n\n", event->des);
	
}

char s_time_start(baza *event1, baza *event2){
	if (event1->year_start > event2->year_start) return 1;
	if (event1->year_start < event2->year_start) return 0;
	else {
		if (event1->mounth_start > event2->mounth_start) return 1;
		if (event1->mounth_start < event2->mounth_start) return 0;
		else{
			if (event1->day_start > event2->day_start) return 1;
			if (event1->day_start < event2->day_start) return 0;
			else{
				if(event1->hours_start > event2->hours_start) return 1;
				if(event1->hours_start < event2->hours_start) return 0;
				else{
					if (event1->min_start > event2->min_start) return 1;
					else return 0;
				}
			}
		}
	}						
}

void s_tStart(baza *event1, baza *event2){
	printf("Сортировка по времени начала мероприятия:\n\n");
	if (s_time_start(event1, event2) == 1){
		output(event2);
		output(event1);
	}
	else{
		output(event1);
		output(event2);	
	}
}

char s_time_stop(baza *event1, baza *event2){
	if (event1->year_stop > event2->year_stop) return 1;
	if (event1->year_stop < event2->year_stop) return 0;
	else {
		if (event1->mounth_stop > event2->mounth_stop) return 1;
		if (event1->mounth_stop < event2->mounth_stop) return 0;
		else{
			if (event1->day_stop > event2->day_stop) return 1;
			if (event1->day_stop < event2->day_stop) return 0;
			else{
				if(event1->hours_stop > event2->hours_stop) return 1;
				if(event1->hours_stop < event2->hours_stop) return 0;
				else{
					if (event1->min_stop > event2->min_stop) return 1;
					else return 0;
				}
			}
		}
	}						
}

void s_tStop(baza *event1, baza *event2){
	printf("Сортировка по времени окончания мероприятия:\n\n");
	if (s_time_stop(event1, event2) == 1) {
		output(event2);
		output(event1);
	}
	else {
		output(event1);
		output(event2);
	}
}

char s_overlapping(baza *event1, baza *event2){
	if (event1->year_stop > event2->year_start) return 1;
	if (event1->year_stop < event2->year_start) return 0;
	else {
		if (event1->mounth_stop > event2->mounth_start) return 1;
		if (event1->mounth_stop < event2->mounth_start) return 0;
		else{
			if (event1->day_stop > event2->day_start) return 1;
			if (event1->day_stop < event2->day_start) return 0;
			else{
				if(event1->hours_stop > event2->hours_start) return 1;
				if(event1->hours_stop < event2->hours_start) return 0;
				else{
					if (event1->min_stop > event2->min_start) return 1;
					else return 0;
				}
			}
		}
	}						
}

char s_Overlap(baza *event1, baza *event2){
	if(s_time_start(event1, event2) == 1) {
		if(s_overlapping(event2, event1) == 0) return 0;
		else return 1;
	}
	else {
		if (s_overlapping(event1, event2) == 0) return 0;
		else return 1;
	}
}

void s_totalOverlap(baza *event1, baza * event2){
	if (s_Overlap(event1, event2) == 0)
		printf("Мероприятия не пересекаются\n\n");
	else
		printf("Мероприятия пересекаются\n\n");
}

void count_interval(baza *event1, baza *event2){
	int min1 = 0, min2 = 0, h1= 0, h2 = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	int total = 0;
	int mounth[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int i = 0, days = 0;
	
	m1 = event1->mounth_stop - 1;
	m2 = event2->mounth_start - 1;
	
	y1 = event1->year_stop - 1;
	y2 = event2->year_start - 1;
	
	min1 = event1->min_stop * 60;
	min2 = event2->min_start * 60;
	
	h1 = event1->hours_stop * 60 * 60;
	h2 = event2->hours_start * 60 * 60;
	
	d1 = event1->day_stop;
	d2 = event2->day_start;
	
	if (event1->year_stop % 4 == 0 || (event1->year_stop % 100 == 0) && (event1->year_stop % 400 == 0)){
		if (m1 > 2) {
			m1 = mounth[m1] + 1;
		}
		else m1 = mounth[m1];
	}
	else m1 = mounth[m1];
	
	if (event2->year_start % 4 == 0 || (event2->year_start % 100 == 0) && (event2->year_start % 400 == 0)){
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
	
	printf("Максимальное время между мероприятиями: %d секунд\n\n", total);
}

void s_free_interval(baza *event1, baza *event2){
	if (s_Overlap(event1, event2) == 0) {
		if (s_time_start(event1, event2)) count_interval(event2, event1);
		else count_interval(event1, event2);
	}
	else printf("У мероприятий нет свободного интервала\n\n");
}

