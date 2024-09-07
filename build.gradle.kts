plugins {
    `cpp-library`
    kotlin("jvm")
}

repositories {
    mavenCentral()
}

dependencies {
    implementation("org.slf4j:slf4j-api:2.1.0-alpha1")
}