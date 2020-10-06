#ifndef __REAL_ESTATE_TEST__CPP
#define __REAL_ESTATE_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("Test for function getEstateByPosition")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60,8,2);
    listOfEstates.addEstate(estates[0]);
    Estate* estate=listOfEstates.getEstateByPosition(0);
    CHECK(strcpy(estate->getTown(),"Plovdiv"));
    CHECK(strcpy(estate->getOwner(),"Olga Petkova"));
    CHECK(estate->getPrice() == 130000);

}
TEST_CASE("Tests removeEstate function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    estates[1]=new Flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    listOfEstates.addEstate(estates[0]);
    listOfEstates.addEstate(estates[1]);
    CHECK(listOfEstates.getCurrent() == 2);
    bool removeResult = listOfEstates.removeEstate(*&estates[1]);
    CHECK(listOfEstates.getCurrent()== 1);
    CHECK(removeResult == 1);
}

TEST_CASE("Tests add function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    listOfEstates.addEstate(estates[0]);
    CHECK(listOfEstates.getCurrent() == 1);
    Estate* estate=listOfEstates.getEstateByPosition(0);
    CHECK(strcpy(estate->getTown(),"Plovdiv"));
    CHECK(strcpy(estate->getOwner(),"Olga Petkova"));
    CHECK(estate->getPrice() == 130000);
}

#endif
