//
//  main.cpp
//  Lab2
//
//  Created by Maxim Butin on 03.06.2020.
//  Copyright © 2020 Maxim Butin. All rights reserved.
//

#include <iostream>
#include <fstream>

// максимальное значение веса
#define INF 101

using namespace std;

void printMatrix(int** matrix, int vertexCount)
{
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            if (matrix[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// matrix - матрица смежности
void floydWarshall(int **matrix, int countVertex) {
    // Пробегаемся по всем вершинам и ищем более короткий путь через вершину k
    for(int k = 0; k < countVertex; k++) {
        for(int i = 0; i < countVertex; i++) {
            for(int j = 0; j < countVertex; j++) {
                // Новое значение ребра равно минимальному между старым и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    ifstream file("/Users/maximbutin/Documents/Study/Paralleling Programmer/Lab2/Lab2/matrix.txt");
    int countVertex;
    file >> countVertex;
    cout << countVertex << endl;
    
    // Матрица смежности с весами ребер графа(101 - ребер нет, 0 ребро в себя)
    int **matrix = (int**)malloc(sizeof(int)*countVertex);
    for (int i = 0; i < countVertex; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*countVertex);
    }
    
    // Считываем матрицу весов ребер
    for (int i = 0; i < countVertex; i++)
    {
        for (int j = 0; j < countVertex; j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();
    
    cout << "Old matrix" << endl;
    printMatrix(matrix, countVertex);
    
    floydWarshall(matrix, countVertex);
    cout << "New matrix" << endl;
    printMatrix(matrix, countVertex);
    
    return 0;
}
