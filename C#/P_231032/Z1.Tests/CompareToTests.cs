using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class CompareToTests
    {
        [Test]
        [Category("CompareTo")]
        public void Animal_CompareTo_ShouldReturnZero_WhenNamesAreEqual()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Max");

            Assert.AreEqual(0, animal1.CompareTo(animal2));
        }

        [Test]
        [Category("CompareTo")]
        public void Animal_CompareTo_ShouldReturnPositive_WhenFirstNameIsGreater()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Charlie");

            Assert.Greater(animal1.CompareTo(animal2), 0);
        }
		
		[Test]
        [Category("CompareTo")]
        public void Cat_CompareTo_ShouldReturnZero_WhenNamesAreEqual()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Whiskers");

            Assert.AreEqual(0, cat1.CompareTo(cat2));
        }

        [Test]
        [Category("CompareTo")]
        public void Cat_CompareTo_ShouldReturnPositive_WhenFirstNameIsGreater()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Bella");

            Assert.Greater(cat1.CompareTo(cat2), 0);
        }
		
		[Test]
        [Category("CompareTo")]
        public void Dog_CompareTo_ShouldReturnZero_WhenNamesAreEqual()
        {
            Dog dog1 = new Dog("Rex");
            Dog dog2 = new Dog("Rex");

            Assert.AreEqual(0, dog1.CompareTo(dog2));
        }

        [Test]
        [Category("CompareTo")]
        public void Dog_CompareTo_ShouldReturnPositive_WhenFirstNameIsGreater()
        {
            Dog dog1 = new Dog("Rex");
            Dog dog2 = new Dog("Bella");

            Assert.Greater(dog1.CompareTo(dog2), 0);
        }
    }
    
}
