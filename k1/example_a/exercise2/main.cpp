#include <iostream>
#include "file.h"
#include "directory.h"

using namespace std;

int main() {
    Directory* root = new Directory("root", 3);

    File* readme = new File("readme.txt", 100);
    root->add(readme);

    Directory* documents = new Directory("documents", 2);

    File* report = new File("report.pdf", 200);
    documents->add(report);

    Directory* images = new Directory("images", 2);

    File* photo = new File("photo.png", 150);
    images->add(photo);

    documents->add(images);
    root->add(documents);

    cout << "Total size: " << root->getSize() << endl;

    delete root;

    return 0;
}
