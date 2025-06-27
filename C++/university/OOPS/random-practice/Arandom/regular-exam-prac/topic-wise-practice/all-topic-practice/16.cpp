#include <iostream>
using namespace std;

class MediaFile {
public:
  virtual void play() = 0; // pure virtual function
  virtual ~MediaFile() {}
};

class MP3 : public MediaFile {
public:
  void play() override { cout << "Playing MP3 audio...\n"; }
};

class Video : public MediaFile {
public:
  void play() override { cout << "Playing video file...\n"; }
};

int main() {
  MediaFile *m1 = new MP3();
  MediaFile *m2 = new Video();

  m1->play();
  m2->play();

  delete m1;
  delete m2;
  return 0;
}
