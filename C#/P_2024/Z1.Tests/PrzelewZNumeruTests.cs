
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class PrzelewZNumeruTests
    {
        FieldInfo saldoRef = typeof(RachunekBankowy).GetField("saldo", BindingFlags.NonPublic | BindingFlags.Instance);

        [Test]
        [Category("PrzelewZNumeru")]
        public void PrzelewZNumeru_SukcesPrzelewu()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunekZ = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunekNa = new RachunekOsobisty("654321", "Anna Nowak");

            rachunekZ.Wp³aæ(500m);
            systemBankowy.RachunkiBankowe.Add(rachunekZ);
            systemBankowy.RachunkiBankowe.Add(rachunekNa);

            // Act
            systemBankowy.Przelew(rachunekZ, "654321", 200m);

            // Assert
            var saldoZ = (decimal)saldoRef.GetValue(rachunekZ);
            var saldoNa = (decimal)saldoRef.GetValue(rachunekNa);
            Assert.AreEqual(300m, saldoZ);
            Assert.AreEqual(200m, saldoNa);
        }

        [Test]
        [Category("PrzelewZNumeru")]
        public void PrzelewZNumeru_NieudanaProbaPrzelewu_BlednyNumer()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunekZ = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunekNa = new RachunekOsobisty("654321", "Anna Nowak");

            rachunekZ.Wp³aæ(500m);
            systemBankowy.RachunkiBankowe.Add(rachunekZ);
            systemBankowy.RachunkiBankowe.Add(rachunekNa);

            // Act
            systemBankowy.Przelew(rachunekZ, "000000", 200m);

            // Assert
            var saldoZ = (decimal)saldoRef.GetValue(rachunekZ);
            var saldoNa = (decimal)saldoRef.GetValue(rachunekNa);
            Assert.AreEqual(500m, saldoZ);
            Assert.AreEqual(0m, saldoNa);
        }
    }
}
