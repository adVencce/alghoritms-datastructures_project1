#include <iostream>
#include <fstream>
using namespace std;

void move(int nums[], int n)
{
    // w tej tablicy przetrzymuje wynik sortowania
    int result[n];

    int j = 0; // index wyniku
    for (int i = 0; i < n ; i++)
        if (nums[i] >= 0 )
            result[j++] = nums[i];
    if (j == n || j == 0)
        return;

    for (int i = 0 ; i < n ; i++)
        if (nums[i] < 0)
            result[j++] = nums[i];

    // kopiuje zawartosc do tablicy nums[]
    memcpy(nums, result, sizeof(result));
}

int main()
{


ofstream zapis("wynik.txt");
if(!zapis) // sprawdzanie czy plik istnieje
{
    cout << "Blad otwarcia pliku!" << endl; 
    exit(1);
}
else
{



    int nums[] = {-10,5,8,-4,1,3,0,-7}; // dane wejsciowe
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Wejscie: ";
    for (int i=0; i < n; i++)
    cout << nums[i] <<" "; //wypisanie elementow tablicy
     move(nums, n); // odwolanie do funkcji void

    printf("\nTablica po sortowaniu: ");
      for (int i=0; i < n; i++)
      {
    cout << nums[i] <<" ";	//wypisanie elementow tablicy
    zapis << nums[i] <<" ";
      }




      zapis.close();

         return 0;
    }




}
