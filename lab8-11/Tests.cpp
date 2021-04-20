#include "Tests.h"
#include <assert.h>

void Test::runAll() {
	this->testShow();
	this->testFilm();
	this->testArtist();
	//this->testRepo();
	this->testRepoFileTXT();
	this->testRepoFileCSV();
	this->testService();
	
}

void Test::testShow() {
	Show s;
	assert(s.getDate() == "");
	assert(s.getPlace() == "");
	assert(s.getAvailablePlaces() == 0);
	assert(s.getOccupiedPlaces() == 0);
	Show s1("10/10/2020", "Cluj", 1000, 276);
	assert(s1.getDate() == "10/10/2020");
	assert(s1.getPlace() == "Cluj");
	assert(s1.getAvailablePlaces() == 1000);
	assert(s1.getOccupiedPlaces() == 276);
	Show s2(s1);
	assert(s2.getDate() == "10/10/2020");
	assert(s2.getPlace() == "Cluj");
	assert(s2.getAvailablePlaces() == 1000);
	assert(s2.getOccupiedPlaces() == 276);
	s2 = s;
	assert(s2.getDate() == "");
	assert(s2.getPlace() == "");
	assert(s2.getAvailablePlaces() == 0);
	assert(s2.getOccupiedPlaces() == 0);
	assert(s2 == s);
	assert(s2.equals(&s));
	s2.copy(&s1);
	assert(s2.getDate() == "10/10/2020");
	assert(s2.getPlace() == "Cluj");
	assert(s2.getAvailablePlaces() == 1000);
	assert(s2.getOccupiedPlaces() == 276);
	s2.setDate("11/12/2021");
	assert(s2.getDate() == "11/12/2021");
	s2.setPlace("Bucuresti");
	assert(s2.getPlace() == "Bucuresti");
	s2.setAvaiablePlaces(2500);
	assert(s2.getAvailablePlaces() == 2500);
	s2.setOccupiedPlaces(1250);
	assert(s2.getOccupiedPlaces() == 1250);
	IE* s3 = s2.clone();
	assert(s2.equals(s3));
	delete s3;
	s3 = nullptr;
}

void Test::testFilm() {
	std::vector<std::string> actors;
	std::vector<Show> shows;
	Film f;
	assert(f.getTitle() == nullptr);
	assert(f.getActors().size() == 0);
	assert(f.getShows().size() == 0);
	actors.emplace_back("Dan");
	char* title = new char[5];
	char* title1 = new char[5];
	strcpy_s(title, strlen("Ana") + 1, "Ana");
	strcpy_s(title1, strlen("Dani") + 1, "Dani");
	Film f1(title, std::vector<std::string>(), "10/10/2012", "Constanta", 450, 300);
	assert((*f1.getTitle()) == *title);
	assert(f1.getActors().size() == 0);
	assert(f1.getShows()[0] == Show("10/10/2012", "Constanta", 450, 300));
	assert(f1.getShows().size() == 1);
	Film f2(f1);
	assert((*f2.getTitle()) == *title);
	assert(f2.getActors().size() == 0);
	assert(f2.getShows()[0] == Show("10/10/2012", "Constanta", 450, 300));
	assert(f2.getShows().size() == 1);
	Show s("10/10/2012", "Constanta", 450, 300);
	shows.emplace_back(s);
	Film f3(title1, actors, shows);
	assert((*f3.getTitle()) == *title1);
	assert(f3.getActors().size() == 1);
	assert(f3.getActors()[0] == "Dan");
	assert(f3.getShows().size() == 1);
	assert(f3.getShows()[0] == s);
	f3 = f1;
	assert((*f3.getTitle()) == *title);
	assert(f3.getActors().size() == 0);
	assert(f3.getShows()[0] == Show("10/10/2012", "Constanta", 450, 300));
	assert(f3.getShows().size() == 1);
	assert(f3 == f1);
	assert(f1 == f3);
	assert(f3.equals(&f1));
	assert(f1.equals(&f3));
	assert(f3.equals(&f2));
	assert(f2.equals(&f3));
	assert(f3 == f2);
	assert(!(f3 == f));
	assert(!f3.equals(&f));
	f3.copy(&f);
	assert(f3.getTitle() == nullptr);
	assert(f3.getActors().size() == 0);
	assert(f3.getShows().size() == 0);
	f.setShows(shows);
	assert(f.getShows().size() == 1);
	assert(f.getShows()[0] == s);
	f.setActors(actors);
	assert(f.getActors().size() == 1);
	assert(f.getActors()[0] == "Dan");
	f.setTitle(title1);
	assert((*f.getTitle()) == *title1);
	IE* f4 = f1.clone();
	assert(f1.equals(f4));
	Film* f5 = new Film;
	f5->copy(f4);
	assert(*(f5->getTitle()) == *title);
	assert(f5->getActors().size() == 0);
	assert(f5->getShows().size() == 1);
	assert(f5->getShows()[0] == Show("10/10/2012", "Constanta", 450, 300));
	delete f5;
	f5 = nullptr;
	delete f4;
	f4 = nullptr;
	delete[] title1;
	title1 = nullptr;
	delete[] title;
	title = nullptr;
}

void Test::testArtist() {
	std::vector<Show> shows;
	char* name = new char[10];
	char* name1 = new char[10];
	strcpy_s(name, strlen("Alex") + 1, "Alex");
	strcpy_s(name1, strlen("Adi") + 1, "Adi");
	Artist a;
	assert(a.getName() == nullptr);
	assert(a.getShows().size() == 0);
	Artist a1(name, "12/12/2012", "Craiova", 1000, 999);
	assert(*(a1.getName()) == *name);
	assert(a1.getShows().size() == 1);
	assert(a1.getShows()[0] == Show("12/12/2012", "Craiova", 1000, 999));
	Show s("09/12/2019", "Cluj", 100, 59);
	shows.emplace_back(s);
	Artist a2(name1, shows);
	assert(*(a2.getName()) == *name1);
	assert(a2.getShows().size() == 1);
	assert(a2.getShows()[0] == s);
	Artist a3(a);
	assert(a3.getName() == nullptr);
	assert(a3.getShows().size() == 0);
	assert(a3 == a);
	assert(a == a3);
	assert(a3.equals(&a));
	assert(a.equals(&a3));
	a3.copy(&a2);
	assert(*(a3.getName()) == *name1);
	assert(a3.getShows().size() == 1);
	assert(a3.getShows()[0] == s);
	a2 = a1;
	a.setShows(shows);
	assert(a.getShows().size() == 1);
	assert(a.getShows()[0] == s);
	a.setShows(std::vector<Show>());
	assert(a.getShows().size() == 0);
	assert(a2 == a1);
	assert(a1 == a2);
	assert(*(a2.getName()) == *name);
	assert(a2.getShows().size() == 1);
	assert(a2.getShows()[0] == Show("12/12/2012", "Craiova", 1000, 999));
	a2.setName(name1);
	assert(*(a2.getName()) == *name1);
	a2.setName(nullptr);
	assert(a2.getName() == nullptr);
	IE* a4 = a3.clone();
	Artist* a5 = new Artist;
	a5->copy(a4);
	assert(*(a5->getName()) == *name1);
	assert(a5->getShows().size() == 1);
	assert(a5->getShows()[0] == s);
	delete a5;
	a5 = nullptr;
	delete a4;
	a4 = nullptr;
	delete[] name1;
	name1 = nullptr;
	delete[] name;
	name = nullptr;
}

//void Test::testRepo() {
//	Repo r;
//	assert(r.getSize() == 0);
//	IE* ar = new Artist();
//	IE* fi = new Film();
//	r.addElem(ar);
//	assert(r.getSize() == 1);
//	r.addElem(fi);
//	assert(r.getSize() == 2);
//	assert(r.getElemPos(ar) == 0);
//	assert(r.getElemPos(fi) == 1);
//	char* name = new char[5];
//	strcpy_s(name, strlen("Ana") + 1, "Ana");
//	IE* f = new Film(name, std::vector<std::string>(), "10/10/2012", "Cluj", 100, 10);
//	r.addElem(f);
//	assert(r.getSize() == 3);
//	assert(r.getElemPos(f) == 2);
//	r.deleteElem(ar);
//	assert(r.getSize() == 2);
//	IE* a = new Artist(name, "11/11/2011", "Bucuresti", 500, 500);
//	r.modifyElem(fi, a);
//	assert(r.getElemByPos(0)->equals(a));
//	std::vector<IE*> elems;
//	elems.emplace_back(f);
//	elems.emplace_back(a);
//	Repo r1(elems);
//	assert(r1.getSize() == 2);
//	assert(r1.getElemPos(a) == 1);
//	assert(r1.getElemPos(f) == 0);
//    assert(r1.getElemByPos(1)->equals(a));
//	assert(r1.getElemByPos(0)->equals(f));
//	delete a;
//	a = nullptr;
//	delete f;
//	f = nullptr;
//	delete[] name;
//	name = nullptr;
//	delete fi;
//	fi = nullptr;
//	delete ar;
//	ar = nullptr;
//
//}

void Test::testRepoFileTXT() {
	Repo* r = new RepoFileTXT ("TestRepoFileTXT.txt");
	char* name = new char[5];
	strcpy_s(name, strlen("Ana") + 1, "Ana");
	IE* f = new Film(name, std::vector<std::string>(), "10/10/2012", "Cluj", 100, 10);
	IE* a = new Artist(name, "11/11/2011", "Bucuresti", 500, 500);
	r->addElem(f);
	r->addElem(a);
	r->saveToFile();
	r->loadFromFile();
	assert(r->getSize() == 2);
	assert(r->getAll()[0]->equals(f));
	assert(r->getElemPos(a) == 1);
	delete a;
	a = nullptr;
	delete f;
	f = nullptr;
	delete[] name;
	name = nullptr;
	delete r;
	r = nullptr;
	remove("TestRepoFileTXT.txt");
}

void Test::testRepoFileCSV() {
	Repo* r = new RepoFileCSV("TestRepoFileCSV.csv");
	char* name = new char[5];
	strcpy_s(name, strlen("Ana") + 1, "Ana");
	IE* f = new Film(name, std::vector<std::string>(), "10/10/2012", "Cluj", 100, 10);
	IE* a = new Artist(name, "11/11/2011", "Bucuresti", 500, 500);
	r->addElem(f);
	r->addElem(a);
	r->saveToFile();
	r->loadFromFile();
	assert(r->getSize() == 2);
	assert(r->getAll()[0]->equals(f));
	assert(r->getElemPos(a) == 1);
	delete a;
	a = nullptr;
	delete f;
	f = nullptr;
	delete[] name;
	name = nullptr;
	delete r;
	r = nullptr;
	remove("TestRepoFileCSV.csv");
}

void Test::testService() {
	;
}