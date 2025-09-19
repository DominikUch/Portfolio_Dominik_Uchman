using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class AnimalCollectionTests
    {
        private AnimalCollection<Animal> animalCollection;

        [SetUp]
        public void SetUp()
        {
            animalCollection = new AnimalCollection<Animal>();
        }

        [Test]
        [Category("AnimalCollection")]
        public void Add_ShouldAddAnimalToCollection()
        {
            var dog = new Dog("Rex");
            animalCollection.Add(dog);

            Assert.Contains(dog, animalCollection.animals);
        }

        [Test]
        [Category("AnimalCollection")]
        public void GetEnumerator_ShouldReturnEnumerator()
        {
            var dog = new Dog("Rex");
            var cat = new Cat("Whiskers");
            animalCollection.Add(dog);
            animalCollection.Add(cat);

            var enumerator = animalCollection.GetEnumerator();

            Assert.IsNotNull(enumerator);
            CollectionAssert.AreEqual(new List<Animal> { dog, cat }, animalCollection);
        }

        [Test]
        [Category("AnimalCollection")]
        public void Collection_ShouldBeEmptyInitially()
        {
            Assert.IsEmpty(animalCollection);
        }

        [Test]
        [Category("AnimalCollection")]
        public void Collection_ShouldHandleMultipleAdditions()
        {
            var dog = new Dog("Rex");
            var cat = new Cat("Whiskers");
            var bird = new Dog("Tweety");  // Dog used for simplicity

            animalCollection.Add(dog);
            animalCollection.Add(cat);
            animalCollection.Add(bird);

            Assert.AreEqual(3, animalCollection.Count);
            CollectionAssert.AreEquivalent(new List<Animal> { dog, cat, bird }, animalCollection);
        }

        [Test]
        [Category("AnimalCollection")]
        public void Collection_ShouldHandleEmptyEnumeration()
        {
            var enumerator = animalCollection.GetEnumerator();

            Assert.IsFalse(enumerator.MoveNext());
        }
    }
    
}
