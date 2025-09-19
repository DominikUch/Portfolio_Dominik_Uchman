using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    internal class ImplicitExplicitTests
    {
        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_DogToString_ValidName()
        {
            // Arrange
            Dog myDog = new Dog("Rex");

            // Act
            string dogName = myDog;

            // Assert
            Assert.AreEqual("Rex", dogName);
        }

        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_DogToString_EmptyName()
        {
            // Arrange
            Dog myDog = new Dog("");

            // Act
            string dogName = myDog;

            // Assert
            Assert.AreEqual("", dogName);
        }

        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_DogToString_NullName()
        {
            // Arrange
            Dog myDog = new Dog(null);

            // Act
            string dogName = myDog;

            // Assert
            Assert.IsNull(dogName);
        }

        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_StringToDog_ValidName()
        {
            // Arrange
            string dogName = "Buddy";

            // Act
            Dog myDog = dogName;

            // Assert
            Assert.IsNotNull(myDog);
            Assert.AreEqual("Buddy", myDog.Name);
        }

        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_StringToDog_EmptyName()
        {
            // Arrange
            string dogName = "";

            // Act
            Dog myDog = dogName;

            // Assert
            Assert.IsNotNull(myDog);
            Assert.AreEqual("", myDog.Name);
        }

        [Test]
        [Category("ImplicitExplicit")]
        public void ImplicitConversion_StringToDog_NullName()
        {
            // Arrange
            string dogName = null;

            // Act
            Dog myDog = dogName;

            // Assert
            Assert.IsNotNull(myDog); // Obiekt Dog powinien zostać stworzony
            Assert.IsNull(myDog.Name); // Ale jego nazwa powinna być null
        }
    }
    
}
