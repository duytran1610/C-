#pragma once
class String;

int Compare(const String& str1, const String& str2);
bool operator<(const String& str1, const String& str2);
bool operator==(const String& str1, const String& str2);
bool operator>(const String& str1, const String& str2);

void Menu();