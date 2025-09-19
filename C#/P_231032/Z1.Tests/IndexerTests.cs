using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    internal class IndexerTests
    {
        private Zoo zoo;

        [SetUp]
        public void SetUp()
        {
            zoo = new Zoo();
            zoo.AddAnimal(new Dog("Buddy"));
            zoo.AddAnimal(new Cat("Whiskers"));
        }

        [Test]
        [Category("Indexer")]
        public void Indexer_ByIndex_ShouldReturnCorrectAnimal()
        {
            // Act
            var animalAtIndex0 = zoo[0];
            var animalAtIndex1 = zoo[1];

            // Assert
            Assert.IsInstanceOf<Dog>(animalAtIndex0);
            Assert.IsInstanceOf<Cat>(animalAtIndex1);
            Assert.AreEqual("Buddy", animalAtIndex0.Name);
            Assert.AreEqual("Whiskers", animalAtIndex1.Name);
        }

        [Test]
        [Category("Indexer")]
        public void Indexer_ByIndex_ShouldSetCorrectAnimal()
        {
            // Arrange
            var newDog = new Dog("Rex");

            // Act
            zoo[1] = newDog; // Zastępujemy drugiego zwierzaka nowym psem

            // Assert
            Assert.AreEqual(newDog, zoo[1]);
            Assert.AreEqual("Rex", zoo[1].Name);
        }

        [Test]
        [Category("Indexer")]
        public void Indexer_ByIndex_InvalidIndex_ShouldThrowException()
        {
            // Assert
            Assert.Throws<IndexOutOfRangeException>(() => { var animal = zoo[-1]; });
            Assert.Throws<IndexOutOfRangeException>(() => { var animal = zoo[2]; });

            // Próba ustawienia zwierzęcia na nieprawidłowym indeksie
            Assert.Throws<IndexOutOfRangeException>(() => { zoo[-1] = new Dog("Rex"); });
            Assert.Throws<IndexOutOfRangeException>(() => { zoo[2] = new Dog("Rex"); });
        }

        [Test]
        [Category("Indexer")]
        public void Indexer_ByName_ShouldReturnCorrectAnimal()
        {
            // Act
            var animalByNameBuddy = zoo["Buddy"];
            var animalByNameWhiskers = zoo["Whiskers"];

            // Assert
            Assert.IsInstanceOf<Dog>(animalByNameBuddy);
            Assert.IsInstanceOf<Cat>(animalByNameWhiskers);
            Assert.AreEqual("Buddy", animalByNameBuddy.Name);
            Assert.AreEqual("Whiskers", animalByNameWhiskers.Name);
        }

        [Test]
        [Category("Indexer")]
        public void Indexer_ByName_InvalidName_ShouldThrowException()
        {
            // Assert
            Assert.Throws<KeyNotFoundException>(() => { var animal = zoo["NonExistent"]; });
        }
    }
    
}
