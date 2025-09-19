
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class PrzelewBezposredniTests
    {
        FieldInfo saldoRef = typeof(RachunekBankowy).GetField("saldo", BindingFlags.NonPublic | BindingFlags.Instance);

        [Test]
        [Category("PrzelewBezposredni")]
        public void PrzelewBezposredni_SukcesPrzelewu()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunekZ = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunekNa = new RachunekOsobisty("654321", "Anna Nowak");

            rachunekZ.Wp³aæ(500m);
            systemBankowy.RachunkiBankowe.Add(rachunekZ);
            systemBankowy.RachunkiBankowe.Add(rachunekNa);

            // Act
            systemBankowy.Przelew(rachunekZ, rachunekNa, 200m);

            // Assert
            var saldoZ = (decimal)saldoRef.GetValue(rachunekZ);
            var saldoNa = (decimal)saldoRef.GetValue(rachunekNa);
            Assert.AreEqual(300m, saldoZ);
            Assert.AreEqual(200m, saldoNa);
        }

        [Test]
        [Category("PrzelewBezposredni")]
        public void PrzelewBezposredni_NieudanaProbaPrzelewu_ZaMaloSrodkow()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunekZ = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunekNa = new RachunekOsobisty("654321", "Anna Nowak");

            rachunekZ.Wp³aæ(100m);
            systemBankowy.RachunkiBankowe.Add(rachunekZ);
            systemBankowy.RachunkiBankowe.Add(rachunekNa);

            // Act
            systemBankowy.Przelew(rachunekZ, rachunekNa, 200m);

            // Assert
            var saldoZ = (decimal)saldoRef.GetValue(rachunekZ);
            var saldoNa = (decimal)saldoRef.GetValue(rachunekNa);
            Assert.AreEqual(100m, saldoZ);
            Assert.AreEqual(0m, saldoNa);
        }
    }
}
