#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sale {
    double value;
    char month[20];
};

double avg(struct Sale sales[], int size, int start, int stop)
{
    double sum = 0.0;
    for (int i = start; i < stop; i++)
    {
        sum += sales[i].value;
    }

    return (sum / (double)(stop-start));
}

struct Sale min(struct Sale sales[], int size)
{
    struct Sale _min = sales[0];
    for (int i = 0; i < size; i++)
    {
        if (sales[i].value < _min.value)
        {
            _min.value = sales[i].value;
            // Copy the month 
            for (int j = 0; j < 20; j++)
            {
                _min.month[j] = sales[i].month[j];
            }
        }
    }

    return _min;
}

struct Sale max(struct Sale sales[], int size)
{
    struct Sale _max = sales[0];
    for (int i = 0; i < size; i++)
    {
        if (&sales[i] == NULL)
        {
            continue;
        }
        if (sales[i].value > _max.value)
        {
            _max.value = sales[i].value;

            // Copy the month 
            for (int j = 0; j < 20; j++)
            {
                _max.month[j] = sales[i].month[j];
            }
        }
    }

    return _max;
}

int compareSales(const void *a, const void *b) {
    double valueA = ((struct Sale *)a)->value;
    double valueB = ((struct Sale *)b)->value;
    
    if (valueA < valueB) return 1;  // We want descending order, so swap the return values
    if (valueA > valueB) return -1;
    return 0;
}

void sortSales(struct Sale *sales, size_t n) {
    qsort(sales, n, sizeof(struct Sale), compareSales);
}

