#include <fstream>
#include <stdio.h>
#include <string>
#include <gtest/gtest.h>

#include <IniReader/ini_reader.h>


class TestIniReader : public testing::Test {
protected:
    std::fstream iniFile1;
    std::fstream iniFile2;
    std::fstream iniFile3;
    std::fstream iniFile4;
    IniReader* iniTest1 {nullptr};
    IniReader* iniTest2 {nullptr};
    IniReader* iniTest3 {nullptr};
    IniReader* iniTest4 {nullptr};

    virtual void SetUp() override {
        iniFile1.open("___testIni1.ini", std::fstream::out);
        iniFile2.open("___testIni2.ini", std::fstream::out);
        iniFile3.open("___testIni3.ini", std::fstream::out);
        iniFile4.open("___testIni4.ini", std::fstream::out);

        // Got it from some random forum online
        // Ini File 1
        iniFile1 << "[Login]" "\n"
                    "Username=398dab303.... (24 Alphanumeric string)" "\n"
                    "Password=0b96b90....(24 Alphanumeric string)" "\n"
                    "[Directory]" "\n"
                    "Software=oePyzIVR" "\n"
                    "[Cheats]" "\n"
                    "DefaultConfig=Config Name";
        
        // Stole this INI file from https://ark.fandom.com/wiki/Game.ini
        // Edited it a bit to make it simpler. This is a super basic reader after all
        // Ini File 2        
        iniFile2 << ""
                    "" "\n"
                    "[Internationalization]" "\n"
                    "" "\n"
                    "LocalizationPaths=../../../ShooterGame/Content/Localization/Game" "\n"
                    "" "\n"
                    "[/Script/Engine.Gamemode]" "\n"
                    "InactivePlayerStateLifeSpan=300" "\n"
                    "" "\n"
                    "[DefaultPlayer]" "\n"
                    "Name=Player" "\n"
                    "" "\n"
                    "[/Script/Engine.GameNetworkManager]" "\n"
                    "MaxIdleTime=+0.0" "\n"
                    "DefaultMaxTimeMargin=+0.0" "\n"
                    "TimeMarginSlack=+1.35" "\n"
                    "DefaultMinTimeMargin=-1.0" "\n"
                    "TotalNetBandwidth=600000" "\n"
                    "MaxDynamicBandwidth=15000" "\n"
                    "MinDynamicBandwidth=15000" "\n"
                    "" "\n"
                    "[/Script/Engine.GameSession]" "\n"
                    "MaxPlayers=500" "\n"
                    "MaxSpectators=2" "\n"
                    "MaxSplitscreensPerConnection=4" "\n"
                    "bRequiresPushToTalk=true" "\n"
                    "" "\n"
                    "[/Script/EngineSettings.GeneralProjectSettings]" "\n"
                    "CompanyName=Studio Wildcard" "\n"
                    "CopyrightNotice=Copyright Wildcard Properties LLC, 2014" "\n"
                    "Description=" "\n"
                    "LicensingTerms=" "\n"
                    "PrivacyPolicy=" "\n"
                    "ProjectVersion=" "\n"
                    "Homepage=www.playark.com" "\n"
                    "SupportContact=support@studiowildcard.com" "\n"
                    "ProjectID=B98903CA42E7089552924ABB552F3FA1" "\n"
                    "ProjectName=ARK: Survival Evolved" "\n"
                    "" "\n"
                    "[/Script/Engine.HUD]" "\n"
                    "ConsoleMessageCount=4" "\n"
                    "ConsoleFontSize=5" "\n"
                    "MessageFontOffset=0" "\n"
                    "bShowHUD=true" "\n"
                    "bShowDirectorInfoDebug=false" "\n"
                    "bShowDirectorInfoHUD=false" "\n"
                    "DebugDisplay=AI" "\n"
                    "" "\n"
                    "[/Script/Engine.PlayerController]" "\n"
                    "InteractDistance=512" "\n"
                    "InputYawScale=2.5" "\n"
                    "InputPitchScale=-1.75" "\n"
                    "InputRollScale=1.0" "\n"
                    "" "\n"
                    "[/Script/Engine.DebugCameraController]" "\n"
                    "bShowSelectedInfo=true" "\n"
                    "" "\n"
                    "[/Script/Engine.WorldSettings]" "\n"
                    "ChanceOfPhysicsChunkOverride=1.0" "\n"
                    "bEnableChanceOfPhysicsChunkOverride=false" "\n"
                    "EnabledPlugins=ExampleDeviceProfileSelector" "\n"
                    "" "\n"
                    "[/Script/ShooterGame.ShooterGameMode]" "\n"
                    "WarmupTime=15" "\n"
                    "RoundTime=300" "\n"
                    "TimeBetweenMatches=15" "\n"
                    "KillScore=2" "\n"
                    "DeathScore=-1" "\n"
                    "DamageSelfScale=0.3" "\n"
                    "MaxBots=1" "\n"
                    "" "\n"
                    "[/Script/ShooterGame.ShooterGameInstance]" "\n"
                    "MainMenuMap=/Game/Maps/MainMenu" "\n"
                    "" "\n"
                    "[/Script/MoviePlayer.MoviePlayerSettings]" "\n"
                    "bWaitForMoviesToComplete=False" "\n"
                    "bMoviesAreSkippable=False" "\n"
                    "" "\n"
                    "[/Script/UnrealEd.ProjectPackagingSettings]" "\n"
                    "BuildConfiguration=PPBC_Shipping" "\n"
                    "FullRebuild=True" "\n"
                    "ForDistribution=True" "\n"
                    "UsePakFile=True" "\n"
                    "UseOBB_InAPK=False" "\n"
                    "CulturesToStage=en" "\n"
                    "CulturesToStage=en_US" "\n"
                    "";

        // Found on random forum online
        // Ini File 3
        iniFile3 << ""
                    "[Info]" "\n"
                    "Company=Random Company" "\n"
                    "Data=X,Y" "\n"
                    "Server=localhost" "\n"
                    "User=username" "\n"
                    "Name=name" "\n"
                    "Port=1000" "\n"
                    "Stores=false" "\n"
                    "Help=/help.txt" "\n"
                    "Debug=false" "\n"
                    "Exclude=io" "\n"
                    "" "\n"
                    "[Geometry]" "\n"
                    "columns=320,181,128" "\n"
                    "fontname=Bitstream Charter" "\n"
                    "split=313,1051" "\n"
                    "at=246,83" "\n"
                    "fontsize=14" "\n"
                    "size=1377,867" "\n"
                    "" "\n"
                    "[Open]" "\n"
                    "General Ledger" "\n"
                    "Reports" "\n"
                    "File Maintainance" "\n"
                    "Accounts Payable" "\n"
                    "Daily Work" "\n"
                    "Pay Invoices" "\n"
                    "File Maintainance" "\n"
                    "Accounts Receivable" "\n"
                    "Payroll" "\n"
                    "Daily Work" "\n"
                    "PayDay Work" "\n"
                    "Reports" "\n"
                    "Quarterly Reports" "\n"
                    "File Maintainance" "\n"
                    "Tax Tables" "\n"
                    "State Tax Tables" "\n"
                    "Year End" "\n"
                    "Bank Reconciliation" "\n"
                    "Utilities" "\n"
                    "";

        // Found on random forum online
        // Ini File 4
        iniFile4 << ""
                    "Application=RandomApp" "\n"
                    "Name=MyWorkstation" "\n"
                    "C++ Version=20" "\n"
                    "C++ Release Date=--/2020" "\n"
                    "SQL Version=SQLite 3" "\n"
                    "";

        iniFile1.close();
        iniFile2.close();
        iniFile3.close();
        iniFile4.close();

        iniTest1 = new IniReader("___testIni1.ini");
        iniTest2 = new IniReader("___testIni2.ini");
        iniTest3 = new IniReader("___testIni3.ini");
        iniTest4 = new IniReader("___testIni4.ini");
    }

    virtual void TearDown() override {
        remove("___testIni1.ini");
        remove("___testIni2.ini");
        remove("___testIni3.ini");
        remove("___testIni4.ini");
        delete iniTest1;
        delete iniTest2;
        delete iniTest3;
        delete iniTest4;
    }
};

TEST(TestIniReaderThrows, testThrowsOnInvalidFile) {
    IniReader *reader {nullptr};
    ASSERT_THROW(reader = new IniReader("file.ini"), std::runtime_error);
    delete reader;
}

TEST(TestIniReaderThrows, testNoThrowOnValidFile) {
    IniReader *reader {nullptr};
    ASSERT_NO_THROW(reader = new IniReader("test.ini"));
    delete reader;
}

TEST_F(TestIniReader, testGetSectionExists) {
    // All these should exist in ini file 1
    ASSERT_NO_THROW(iniTest1->getSection("Login"));
    ASSERT_NO_THROW(iniTest1->getSection("Directory"));
    ASSERT_NO_THROW(iniTest1->getSection("Cheats"));
    ASSERT_NO_THROW(iniTest1->getSection());
    ASSERT_NO_THROW(iniTest1->getSection("__global__"));


    // All these should exist in ini file 2
    ASSERT_NO_THROW(iniTest2->getSection("Internationalization"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.Gamemode"));
    ASSERT_NO_THROW(iniTest2->getSection("DefaultPlayer"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.GameNetworkManager"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.GameSession"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.HUD"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.PlayerController"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.DebugCameraController"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/Engine.WorldSettings"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/ShooterGame.ShooterGameMode"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/ShooterGame.ShooterGameInstance"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/MoviePlayer.MoviePlayerSettings"));
    ASSERT_NO_THROW(iniTest2->getSection("/Script/UnrealEd.ProjectPackagingSettings"));
    ASSERT_NO_THROW(iniTest2->getSection());
    ASSERT_NO_THROW(iniTest2->getSection("__global__"));

    // All these should exist in ini file 3
    ASSERT_NO_THROW(iniTest3->getSection("Info"));
    ASSERT_NO_THROW(iniTest3->getSection("Geometry"));
    ASSERT_NO_THROW(iniTest3->getSection("Open"));
    ASSERT_NO_THROW(iniTest3->getSection());
    ASSERT_NO_THROW(iniTest3->getSection("__global__"));

    // All these should exist in ini file 4
    ASSERT_NO_THROW(iniTest4->getSection());
    ASSERT_NO_THROW(iniTest4->getSection("__global__"));
}

TEST_F(TestIniReader, testGetSectionDoesntExists) {
    ASSERT_THROW(iniTest1->getSection("149Aor"), std::runtime_error);
    ASSERT_THROW(iniTest1->getSection("FJibNQ"), std::runtime_error);
    ASSERT_THROW(iniTest1->getSection("10Z4pQ"), std::runtime_error);
    ASSERT_THROW(iniTest1->getSection("01Cams"), std::runtime_error);
    ASSERT_THROW(iniTest1->getSection("s2t7B1"), std::runtime_error);

    ASSERT_THROW(iniTest2->getSection("yIsDeQ"), std::runtime_error);
    ASSERT_THROW(iniTest2->getSection("ANH4ws"), std::runtime_error);
    ASSERT_THROW(iniTest2->getSection("AKMutu"), std::runtime_error);
    ASSERT_THROW(iniTest2->getSection("ic3Gav"), std::runtime_error);
    ASSERT_THROW(iniTest2->getSection("8DQAeH"), std::runtime_error);

    ASSERT_THROW(iniTest3->getSection("AOSGRs"), std::runtime_error);
    ASSERT_THROW(iniTest3->getSection("SoDoyG"), std::runtime_error);
    ASSERT_THROW(iniTest3->getSection("13NZOZ"), std::runtime_error);
    ASSERT_THROW(iniTest3->getSection("cEbGyy"), std::runtime_error);
    ASSERT_THROW(iniTest3->getSection("GHrgUP"), std::runtime_error);

    ASSERT_THROW(iniTest4->getSection("s2Kfxd"), std::runtime_error);
    ASSERT_THROW(iniTest4->getSection("zjN56d"), std::runtime_error);
    ASSERT_THROW(iniTest4->getSection("AiIfHU"), std::runtime_error);
    ASSERT_THROW(iniTest4->getSection("0vwJeq"), std::runtime_error);
    ASSERT_THROW(iniTest4->getSection("WhKPBQ"), std::runtime_error);
}

TEST_F(TestIniReader, testGetKeyValueExists) {
    // test for ini file 1
    ASSERT_EQ(iniTest1->getSection("Login")->at("Username"), "398dab303.... (24 Alphanumeric string)");
    ASSERT_EQ(iniTest1->getSection("Login")->at("Password"), "0b96b90....(24 Alphanumeric string)");
    ASSERT_EQ(iniTest1->getSection("Directory")->at("Software"), "oePyzIVR");
    ASSERT_EQ(iniTest1->getSection("Cheats")->at("DefaultConfig"), "Config Name");

    // test for ini file 2
    ASSERT_EQ(iniTest2->getSection("Internationalization")->at("LocalizationPaths"), "../../../ShooterGame/Content/Localization/Game");
    ASSERT_EQ(iniTest2->getSection("/Script/Engine.Gamemode")->at("InactivePlayerStateLifeSpan"), "300");
    ASSERT_EQ(iniTest2->getSection("DefaultPlayer")->at("Name"), "Player");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("CompanyName"), "Studio Wildcard");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("CopyrightNotice"), "Copyright Wildcard Properties LLC, 2014");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("Description"), "");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("LicensingTerms"), "");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("PrivacyPolicy"), "");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("ProjectVersion"), "");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("Homepage"), "www.playark.com");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("SupportContact"), "support@studiowildcard.com");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("ProjectID"), "B98903CA42E7089552924ABB552F3FA1");
    ASSERT_EQ(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("ProjectName"), "ARK: Survival Evolved");
    
    // test for ini file 3
    ASSERT_EQ(iniTest3->getSection("Info")->at("Company"), "Random Company");
    ASSERT_EQ(iniTest3->getSection("Info")->at("Data"), "X,Y");
    ASSERT_EQ(iniTest3->getSection("Info")->at("Server"), "localhost");
    ASSERT_EQ(iniTest3->getSection("Info")->at("User"), "username");
    ASSERT_EQ(iniTest3->getSection("Info")->at("Name"), "name");
    ASSERT_EQ(iniTest3->getSection("Info")->at("Port"), "1000");
    ASSERT_EQ(iniTest3->getSection("Geometry")->at("columns"), "320,181,128");
    ASSERT_EQ(iniTest3->getSection("Geometry")->at("fontname"), "Bitstream Charter");
    ASSERT_EQ(iniTest3->getSection("Geometry")->at("split"), "313,1051");
    ASSERT_EQ(iniTest3->getSection("Open")->at("General Ledger"), "");
    ASSERT_EQ(iniTest3->getSection("Open")->at("Reports"), "");
    ASSERT_EQ(iniTest3->getSection("Open")->at("File Maintainance"), "");
    ASSERT_EQ(iniTest3->getSection("Open")->at("Accounts Payable"), "");

    // test for ini file 4
    ASSERT_EQ(iniTest4->getSection()->at("Application"), "RandomApp");
    ASSERT_EQ(iniTest4->getSection()->at("Name"), "MyWorkstation");
    ASSERT_EQ(iniTest4->getSection()->at("C++ Version"), "20");
    ASSERT_EQ(iniTest4->getSection()->at("C++ Release Date"), "--/2020");
    ASSERT_EQ(iniTest4->getSection()->at("SQL Version"), "SQLite 3");
    ASSERT_EQ(iniTest4->getSection("__global__")->at("Application"), "RandomApp");
    ASSERT_EQ(iniTest4->getSection("__global__")->at("Name"), "MyWorkstation");
    ASSERT_EQ(iniTest4->getSection("__global__")->at("C++ Version"), "20");
    ASSERT_EQ(iniTest4->getSection("__global__")->at("C++ Release Date"), "--/2020");
    ASSERT_EQ(iniTest4->getSection("__global__")->at("SQL Version"), "SQLite 3");
}

TEST_F(TestIniReader, testGetKeyValueDoesntExist) {
    // test for ini file 1
    ASSERT_ANY_THROW(iniTest1->getSection("Login")->at("QJbdZLv"));
    ASSERT_ANY_THROW(iniTest1->getSection("Directory")->at("seqJxDI"));
    ASSERT_ANY_THROW(iniTest1->getSection("Cheats")->at("zBDeolo"));
    ASSERT_ANY_THROW(iniTest1->getSection("Login")->at("AXaKqwd"));
    ASSERT_ANY_THROW(iniTest1->getSection("Directory")->at("ikoQCwY"));

    // test for ini file 2
    ASSERT_ANY_THROW(iniTest2->getSection("Internationalization")->at("cQJCAsc"));
    ASSERT_ANY_THROW(iniTest2->getSection("/Script/Engine.Gamemode")->at("ZczPStt"));
    ASSERT_ANY_THROW(iniTest2->getSection("DefaultPlayer")->at("ACtNLrE"));
    ASSERT_ANY_THROW(iniTest2->getSection("/Script/EngineSettings.GeneralProjectSettings")->at("hqUjRSz"));
    ASSERT_ANY_THROW(iniTest2->getSection("Internationalization")->at("sahsTvn"));

    // test for ini file 3
    ASSERT_ANY_THROW(iniTest3->getSection("Info")->at("NmZzHti"));
    ASSERT_ANY_THROW(iniTest3->getSection("Geometry")->at("OsTMxab"));
    ASSERT_ANY_THROW(iniTest3->getSection("Open")->at("rqSHvOF"));
    ASSERT_ANY_THROW(iniTest3->getSection("Info")->at("KnJDsZv"));
    ASSERT_ANY_THROW(iniTest3->getSection("Geometry")->at("jiBVjtg"));

    // test for ini file 4
    ASSERT_ANY_THROW(iniTest4->getSection()->at("NNUZVZS"));
    ASSERT_ANY_THROW(iniTest4->getSection()->at("JblJNSx"));
    ASSERT_ANY_THROW(iniTest4->getSection()->at("bxbJDLC"));
    ASSERT_ANY_THROW(iniTest4->getSection()->at("HsHLqLv"));
    ASSERT_ANY_THROW(iniTest4->getSection()->at("mqzAQXe"));
    ASSERT_ANY_THROW(iniTest4->getSection("__global__")->at("NNUZVZS"));
    ASSERT_ANY_THROW(iniTest4->getSection("__global__")->at("JblJNSx"));
    ASSERT_ANY_THROW(iniTest4->getSection("__global__")->at("bxbJDLC"));
    ASSERT_ANY_THROW(iniTest4->getSection("__global__")->at("HsHLqLv"));
    ASSERT_ANY_THROW(iniTest4->getSection("__global__")->at("mqzAQXe"));

}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}