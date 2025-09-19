using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Reflection;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    internal class AttributesTests
    {
        [Test]
        [Category("Attributes")]
        public void AddMethod_ObsoleteAttribute_ShouldDisplayWarning()
        {
            // Arrange
            string expectedMessage = "Use AddAnimal method instead.";
            var animal = new Dog("Rex");

            // Act
            MethodInfo methodInfo = typeof(Zoo).GetMethod("Add");
            IEnumerator<ObsoleteAttribute> e = methodInfo.GetCustomAttributes<ObsoleteAttribute>().GetEnumerator();
            e.MoveNext();
            var obsoleteAttribute = e.Current;

            // Assert
            Assert.IsNotNull(obsoleteAttribute, "Add method should be marked as Obsolete.");
            Assert.AreEqual(expectedMessage, obsoleteAttribute.Message);
        }
    }
    
}

