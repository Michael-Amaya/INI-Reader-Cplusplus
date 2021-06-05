#include <iostream>
#include <string>
#include <gtest/gtest.h>

#include <IniReader/ini_reader.h>

/*class TestIniReader : public testing::Test {
protected:
    IniReader *reader;
public:

    virtual void SetUp() override {
        reader = new IniReader("Name");
    }

    virtual void TearDown() override {
        delete reader;
    }
};*/

TEST(TestIniReader, testThrowsOnInvalidFile) {
    IniReader *reader {nullptr};
    ASSERT_THROW(reader = new IniReader("file.ini"), std::runtime_error);
    delete reader;
}

TEST(TestIniReader, testNoThrowOnValidFile) {
    IniReader *reader {nullptr};
    ASSERT_NO_THROW(reader = new IniReader("test.ini"));
    delete reader;
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}