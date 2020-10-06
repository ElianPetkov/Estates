#ifndef ESTATE_TEST__CPP
#define ESTATE_TEST__CPP
#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("test getTypeOfEstate")
{
    Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getOfferType(),"Classic"));
}

TEST_CASE("test getTown")
{
   Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getTown(),"Plovdiv"));
}

TEST_CASE("test getAddress")
{
    Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getAddr(),"bul. Dunav 1"));
}

TEST_CASE("test getOwner")
{
    Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(!strcmp(estate.getOwner(),"Olga Petkova"));
}

TEST_CASE("test getPrice")
{
    Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(estate.getPrice() == 130000);
}


TEST_CASE("test getSpace")
{
    Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
    CHECK(estate.getSpace() == 60);
}

TEST_CASE("test setPrice")
{
     Estate estate("House","Plovdiv","Classic","bul. Dunav 1","Olga Petkova",130000,60);
     estate.setPrice(120000);
     CHECK(estate.getPrice() == 120000);
}

#endif
