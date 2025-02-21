// Минимальное время на N поездок.
// K водителей ездят по маршрутам, i-ый водитель автобуса проезжает свой маршрут за T[i] минут.
// Сколько минут потребуется (Tmin), чтобы все водители совершили N поездок (завершенных маршрутов)?
// Все маршруты независимы.
// Пример:
// 3 водителя с маршрутами T = { 1, 2, 3 };
// t/1 + t/2 + t/3 = n
// За сколько минут они завершат 5 маршрутов?
// За 1 минуту они завершат 1 маршрут.
// За 2 минуты они завершат 3 маршрута.
// За 3 минуты они завершат 5 маршрутов.

#include <stdio.h>

int total_routes(int drivers[], int drivers_num, int time)
{
    int sum = 0;
    for (int i = 0; i < drivers_num; i++){
        sum += time / drivers[i];
    }
    return sum;
}

int func_minbound(int (*f) (int*,int,int), int left, int right, int value, int arr[], int size)
{

    // value > f(left) and value <= f(right)
    while (right - left > 1)
    {
        int mid = (left + right)/2;

        if (value <= f(arr,size,mid)){
            right = mid;
        }    
        else
        {
            left = mid;
        }
    }    

    return right;
}

int min_time(int drivers[], int drivers_num, int routes_num)
{
    int min_t = drivers[0];
    for (int i = 0; i < drivers_num; i++)
    {
        if (min_t < drivers[i])
        {
            min_t = drivers[i];
        } 
    }
    return func_minbound(&total_routes, 0, min_t * routes_num, routes_num, drivers, drivers_num);
}

int main()
{
    int drivers[3] = {1, 2, 3};
    int drivers_num = 3;
    int routes_num = 5;
    int answer = min_time(drivers, drivers_num, routes_num);
    printf("%d\n", answer);
    
    
    return 0;
}
