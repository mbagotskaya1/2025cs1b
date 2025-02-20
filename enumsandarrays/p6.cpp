#include<iostream> 
#include<fstream> 
using namespace std; 

int readInvervals(int a[][2], string filename= "intervals.txt") { 
    ifstream f(filename);
    int count = 0; 
    while(!f.eof()) { 
        f >> a[count][0];
        f >> a[count][1];
        count++;
    }
    f.close();
    return count; 
}

void printIntervals(int a[][2], int count) { 
    for(int i = 0; i < count; i++) { 
        cout << a[i][0] << " " << a[i][1] << endl; 
    }
}

bool overlaps(int interval1[2], int interval2[2]) { 
    return interval2[0] <= interval1[1];
}

void merge(int interval1[2], int interval2[2], int b[][2], int count) { 
    b[count][0] = interval1[0];
    b[count][1] = interval2[1];
}

int mergeIntervals(int a[][2], int b[][2],int count) { 
    int countInb = 0; 
    for(int i = 0; i < count; i++) { 
        if (i < count - 1 and overlaps(a[i], a[i+1])) {
            merge(a[i], a[i+1], b, countInb);
            i++; 
        } else { 
            b[countInb][0] = a[i][0];
            b[countInb][1] = a[i][1];
        }
        countInb++; 
    }
    return countInb;
}

int main() { 
    int a[100][2]; // assuming max of 100 intervals
    int intervalCount = 0; 
    intervalCount = readInvervals(a);
    printIntervals(a, intervalCount);
    int b[100][2]; 
    int mergedIntervalsCount = mergeIntervals(a, b, intervalCount);
    cout << "Merged:\n";
    printIntervals(b, mergedIntervalsCount);
}