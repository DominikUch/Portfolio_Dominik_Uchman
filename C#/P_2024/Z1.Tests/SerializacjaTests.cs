
using Newtonsoft.Json;
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class SerializacjaTests
    {
        [Test]
        [Category("Serializacja")]
        public void Serializuj_PoprawnieSerializujeListeRachunkow()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek1 = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunek2 = new RachunekFirmowy("654321", "Anna Nowak", "Firma XYZ");
            systemBankowy.RachunkiBankowe.Add(rachunek1);
            systemBankowy.RachunkiBankowe.Add(rachunek2);

            // Act
            string json = systemBankowy.Serializuj();

            // Assert
            string expectedJson = JsonConvert.SerializeObject(systemBankowy.RachunkiBankowe, Newtonsoft.Json.Formatting.Indented, new JsonSerializerSettings
            {
                TypeNameHandling = TypeNameHandling.Auto
            });
            Assert.AreEqual(expectedJson, json);
        }

        [Test]
        [Category("Serializacja")]
        public void Serializuj_PustaListaRachunkow_ZwracaPustaListe()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();

            // Act
            string json = systemBankowy.Serializuj();

            // Assert
            string expectedJson = "[]";
            Assert.AreEqual(expectedJson, json);
        }
    }
}
