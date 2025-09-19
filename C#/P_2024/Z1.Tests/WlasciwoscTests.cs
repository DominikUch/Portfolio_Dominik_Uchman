
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    public class WlasciwoscTests
    {
        [Test]
        [Category("W�a�ciwo��")]
        public void NumerRachunku_Getter_Dzia�aPoprawnie()
        {
            // Arrange
            string numerRachunku = "123456789";
            RachunekBankowy rachunek = new RachunekOsobisty(numerRachunku, "Jan Kowalski");

            // Act
            string retrievedNumerRachunku = rachunek.NumerRachunku;

            // Assert
            Assert.AreEqual(numerRachunku, retrievedNumerRachunku);
        }

        [Test]
        [Category("W�a�ciwo��")]
        public void Wlasciciel_Getter_Dzia�aPoprawnie()
        {
            // Arrange
            string w�a�ciciel = "Jan Kowalski";
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", w�a�ciciel);

            // Act
            string retrievedW�a�ciciel = rachunek.W�a�ciciel;

            // Assert
            Assert.AreEqual(w�a�ciciel, retrievedW�a�ciciel);
        }

        [Test]
        [Category("W�a�ciwo��")]
        public void NumerRachunku_Setter_NieJestDostepny()
        {
            // Arrange
            PropertyInfo propertyInfo = typeof(RachunekBankowy).GetProperty("NumerRachunku");
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            // Act
            bool isSetterAvailable = propertyInfo.GetSetMethod(true) != null;

            // Assert
            Assert.IsFalse(isSetterAvailable);
        }

        [Test]
        [Category("W�a�ciwo��")]
        public void Wlasciciel_Setter_NieJestDostepny()
        {
            // Arrange
            PropertyInfo propertyInfo = typeof(RachunekBankowy).GetProperty("W�a�ciciel");
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            // Act
            bool isSetterAvailable = propertyInfo.GetSetMethod(true) != null;

            // Assert
            Assert.IsFalse(isSetterAvailable);
        }
    }
}
