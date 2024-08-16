plugins {
    kotlin("jvm") version "2.0.0"
}

repositories {
    mavenCentral()
}

sourceSets {
    main {
        java {
            srcDir("java/src/main")
        }
        resources {
            srcDir("java/src/main/resources")
        }
    }
    test {
        java {
            srcDir("java/src/test")
        }
        resources {
            srcDir("java/src/test/resources")
        }
    }
}