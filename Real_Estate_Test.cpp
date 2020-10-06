#ifndef __REAL_ESTATE_TEST__CPP
#define __REAL_ESTATE_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("Tests removeEstate function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estate->resize();

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
    listOfEstates.removeEstate(*&estates[1]);
    CHECK(listOfEstates.getCurrent()== 1);
}

TEST_CASE("Tests add function in RealEstate class")
{
    RealEstates listOfEstates;
    Estate **estates = new Estate*[2];
    estates[0]=new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkov",130000,60,8,2);
    estates[1]=new Flat("Plovdiv","Vip","bul. Dunav 1","Veslin Petkov",120000,65,4,4);
    listOfEstates.addEstate(estates[0]);
    listOfEstates.addEstate(estates[1]);
    CHECK(listOfEstates.getCurrent() == 2);
}

#endif
