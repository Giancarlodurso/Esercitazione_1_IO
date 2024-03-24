#include <iostream>
#include <fstream>

double mappa(double value)
{
    return (value - 1) * (2 - (-1)) / (5 - 1) + (-1);
}


int main()
{
    std::string fileName("data.csv");
    std::ifstream inFile(fileName);
    std::ofstream outFile("result.csv");

    if(inFile.fail())
    {
        std::cerr << "The file does not exist!";
        return 1;
    }

    double sum = 0.0;
    double value = 0.0;
    unsigned int n = 0;
    outFile << "N Mean" << std::endl;


    while(inFile >> value)
    {
        double valMap = mappa(value);   //Questi sono i valori mappati
        sum += valMap;
        n++;
        double mean = sum/n;
        outFile << mean << std::endl;

    }

    inFile.close();
    outFile.close();

    return 0;
}
