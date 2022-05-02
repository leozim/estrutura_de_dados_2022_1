#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void createData(vector<string>& inputData, vector<string>& inputQuery)
{
    int sizeData {};
    cout << "Digite o tamanho do vetor de busca: ";
    cin >> sizeData;

    string data;
    cout << "Digite os dados do vetor de busca separado por espacos: ";

    while (sizeData-- > 0)
    {
        cin >> data;
        inputData.push_back(data);
    }

    int sizeQuery;
    cout << "Digite o tamanhodo vetor de consultas: ";
    cin >> sizeQuery;
    
    cout << "Digite os dados do vetor de consulta separado por espacos: ";
    while (sizeQuery-- > 0)
    {
        cin >> data;
        inputQuery.push_back(data);
    }
}

void show(vector<string> data, vector<string> query)
{
    cout << "[ ";
    for (auto row : data)
        cout << row << " ";
    cout << "]" << endl;

    cout << "[ ";
    for (auto row : query)
        cout << row << " ";
    cout << "]";
}

void showresult(vector<int> result)
{
    cout << "\n resultado: ";
    cout << "[ ";
    for (auto row : result)
        cout << row << " ";
    cout << "]";
}

vector<int> matchingStrings(vector<string> data, vector<string> query)
{
    vector<int> vet {};

    for (int i = 0, size = query.size(); i < size; i++)
    {
        int count = 0;

        for (int k = 0, size2 = data.size(); k < size2; k++)
        {
            if (query[i] == data[k]) count++;
        }

        if ( count > 0)
        {
            vet.push_back(count);
            count = 0;
        }
    }

    return vet;
}

int main()
{
    vector<string> data;
    vector<string> query;
    createData(data, query);

    show(data, query);

    vector<int> result = matchingStrings(data, query);
    showresult(result);

    return 0;
}