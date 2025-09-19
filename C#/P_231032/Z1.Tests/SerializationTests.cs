using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    internal class SerializationTests
    {
        [Test]
        [Category("Serialization")]
        public void Serialize_Dog_ReturnsValidJsonString()
        {
            // Arrange
            Dog myDog = new Dog("Rex");

            // Act
            string json = Animal.Serialize(myDog);

            // Assert
            StringAssert.Contains("Rex", json); // Sprawdzenie, czy JSON zawiera właściwość Name z wartością "Rex"
            StringAssert.Contains("Dog", json); // Sprawdzenie, czy JSON zawiera informację o typie Dog
        }

        [Test]
        [Category("Serialization")]
        public void Serialize_Cat_ReturnsValidJsonString()
        {
            // Arrange
            Cat myCat = new Cat("Whiskers");

            // Act
            string json = Animal.Serialize(myCat);

            // Assert
            StringAssert.Contains("Whiskers", json); // Sprawdzenie, czy JSON zawiera właściwość Name z wartością "Whiskers"
            StringAssert.Contains("Cat", json); // Sprawdzenie, czy JSON zawiera informację o typie Cat
        }

        [Test]
        [Category("Serialization")]
        public void SerializeDeserialize_DogObject_RetainsOriginalData()
        {
            // Arrange
            Dog originalDog = new Dog("Buddy");

            // Act
            string json = Animal.Serialize(originalDog);
            Animal deserializedAnimal = Animal.Deserialize(json);

            // Assert
            Assert.IsInstanceOf<Dog>(deserializedAnimal); // Sprawdzenie, czy zdeserializowany obiekt jest typu Dog
            Assert.AreEqual(originalDog.Name, deserializedAnimal.Name); // Sprawdzenie, czy właściwość Name pozostała niezmieniona
        }

        [Test]
        [Category("Serialization")]
        public void SerializeDeserialize_CatObject_RetainsOriginalData()
        {
            // Arrange
            Cat originalCat = new Cat("Mittens");

            // Act
            string json = Animal.Serialize(originalCat);
            Animal deserializedAnimal = Animal.Deserialize(json);

            // Assert
            Assert.IsInstanceOf<Cat>(deserializedAnimal); // Sprawdzenie, czy zdeserializowany obiekt jest typu Cat
            Assert.AreEqual(originalCat.Name, deserializedAnimal.Name); // Sprawdzenie, czy właściwość Name pozostała niezmieniona
        }
    }
    
}
