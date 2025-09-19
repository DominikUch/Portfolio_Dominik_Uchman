
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class DeserializacjaTests
    {
        [Test]
        [Category("Deserializacja")]
        public void Deserializuj_PoprawnieDeserializujeListeRachunkow()
        {
            // Arrange
            var json = @"
            [
                {
                    '$type': 'Z1.RachunekOsobisty, Z1',
                    'NumerRachunku': '123456',
                    'W³aœciciel': 'Jan Kowalski'
                },
                {
                    '$type': 'Z1.RachunekFirmowy, Z1',
                    'NumerRachunku': '654321',
                    'W³aœciciel': 'Anna Nowak',
                    'nazwaFirmy': 'Firma XYZ'
                }
            ]";
            var systemBankowy = new SystemBankowy();

            // Act
            var deserializedRachunki = systemBankowy.Deserializuj(json);

            // Assert
            Assert.AreEqual(2, deserializedRachunki.Count);
            Assert.IsInstanceOf<RachunekOsobisty>(deserializedRachunki[0]);
            Assert.IsInstanceOf<RachunekFirmowy>(deserializedRachunki[1]);
            Assert.AreEqual("123456", deserializedRachunki[0].NumerRachunku);
        }

        [Test]
        [Category("Deserializacja")]
        public void Deserializuj_PustaListaJSON_ZwracaPustaListe()
        {
            // Arrange
            var json = "[]";
            var systemBankowy = new SystemBankowy();

            // Act
            var deserializedRachunki = systemBankowy.Deserializuj(json);

            // Assert
            Assert.IsNotNull(deserializedRachunki);
            Assert.AreEqual(0, deserializedRachunki.Count);
        }
    }
}
