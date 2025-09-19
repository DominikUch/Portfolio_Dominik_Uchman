
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    public class WlasciwoscTests
    {
        [Test]
        [Category("W³aœciwoœæ")]
        public void NumerRachunku_Getter_Dzia³aPoprawnie()
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
        [Category("W³aœciwoœæ")]
        public void Wlasciciel_Getter_Dzia³aPoprawnie()
        {
            // Arrange
            string w³aœciciel = "Jan Kowalski";
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", w³aœciciel);

            // Act
            string retrievedW³aœciciel = rachunek.W³aœciciel;

            // Assert
            Assert.AreEqual(w³aœciciel, retrievedW³aœciciel);
        }

        [Test]
        [Category("W³aœciwoœæ")]
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
        [Category("W³aœciwoœæ")]
        public void Wlasciciel_Setter_NieJestDostepny()
        {
            // Arrange
            PropertyInfo propertyInfo = typeof(RachunekBankowy).GetProperty("W³aœciciel");
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            // Act
            bool isSetterAvailable = propertyInfo.GetSetMethod(true) != null;

            // Assert
            Assert.IsFalse(isSetterAvailable);
        }
    }
}
