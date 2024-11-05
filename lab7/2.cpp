#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ฟังก์ชันแปลงตัวอักษรเป็นค่าลำดับ (A = 1, B = 2, ..., Z = 26)
int order(char c)
{
    return c - 'A' + 1;
}

// ฟังก์ชันแฮชที่ใช้ในการคำนวณตำแหน่งใน Hash Table
int hashFunction(const string &s, int Z)
{
    int sum = 0;
    for (char c : s)
    {
        sum += order(c); // รวมค่าลำดับของตัวอักษร
    }
    return sum % Z; // คำนวณค่า mod Z
}

// ฟังก์ชันสำหรับใส่ค่าใน Hash Table
void insertToHashTable(vector<string> &hashTable, const string &s, int Z)
{
    int index = hashFunction(s, Z);
    while (!hashTable[index].empty())
    { // ถ้าช่องไม่ว่าง ให้เลื่อนไปช่องถัดไป
        index = (index + 1) % Z;
    }
    hashTable[index] = s; // ใส่สตริงลงในช่องที่ว่าง
}

// ฟังก์ชันสำหรับแสดงตารางแฮช
void displayHashTable(const vector<string> &hashTable)
{
    for (const string &entry : hashTable)
    {
        cout << entry << " ";
    }
    cout << endl;
}

int main()
{
    // ข้อมูลชุดที่ 1
    int Z1 = 10, n1 = 4;
    vector<string> words1 = {"WEE", "ALGO", "CPE", "KMUTT"};
    vector<string> hashTable1(Z1, "NULL");

    // ใส่คำแต่ละคำลงใน Hash Table ชุดที่ 1
    for (const string &word : words1)
    {
        insertToHashTable(hashTable1, word, Z1);
    }

    // แสดงผล Hash Table ชุดที่ 1
    displayHashTable(hashTable1);

    // ข้อมูลชุดที่ 2
    int Z2 = 7, n2 = 6;
    vector<string> words2 = {"AA", "B", "CD", "EF", "GH", "III"};
    vector<string> hashTable2(Z2, "NULL");

    // ใส่คำแต่ละคำลงใน Hash Table ชุดที่ 2
    for (const string &word : words2)
    {
        insertToHashTable(hashTable2, word, Z2);
    }

    // แสดงผล Hash Table ชุดที่ 2
    displayHashTable(hashTable2);

    return 0;
}
