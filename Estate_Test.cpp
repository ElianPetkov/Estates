#ifndef ESTATE_TEST__CPP
#define ESTATE_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("test getTypeOfEstate")
{
    Estate estate("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getTypeOfEstate(),"Classic"));
}

TEST_CASE("test getTown")
{
    Estate estate("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getTown(),"Plovdiv"));
}

TEST_CASE("test getAddress")
{
    Estate estate("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getAddr(),"bul. Dunav 1"));
}

TEST_CASE("test getOwner")
{
    Estate estate("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getOwner(),"Olga Petkova"));
}

TEST_CASE("test getPrice")
{
    Estate estate("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(estate.getPrice() == 130000);
}


TEST_CASE("test getSpace")
{
    Estate* house = new House("Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60,8,2);
    CHECK(house->getSpace() == 60);
}

#endif
