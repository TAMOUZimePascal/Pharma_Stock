-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 25 mai 2024 à 17:01
-- Version du serveur : 10.4.22-MariaDB
-- Version de PHP : 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `pharmastock`
--

-- --------------------------------------------------------

--
-- Structure de la table `personnel`
--

CREATE TABLE `personnel` (
  `idPers` int(5) NOT NULL,
  `codePers` varchar(30) NOT NULL,
  `nomPers` varchar(50) NOT NULL,
  `prenomPers` varchar(50) NOT NULL,
  `contactPers` varchar(50) NOT NULL,
  `mailPers` varchar(50) NOT NULL,
  `password` varchar(255) NOT NULL,
  `rolePers` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `personnel`
--

INSERT INTO `personnel` (`idPers`, `codePers`, `nomPers`, `prenomPers`, `contactPers`, `mailPers`, `password`, `rolePers`) VALUES
(1, 'P001', 'YAI', 'Luc', '+22966554411', 'yai@gmail.com', '0', 'Responsable de vente'),
(2, 'P002', 'BEN', 'Marc', '+3321456545', 'dupond@gmail.com', '0', 'Responsable de stock'),
(4, 'P03', 'ADEOTTI', 'Afisse', '+22961359067', 'adeotiafisse@gmail.com', '4648ea51de952f4b74dc7d1aa6cdfb0d4a58ef4ee85ba05a4f649c3d3f41ebd1', 'Responsable de vente');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `personnel`
--
ALTER TABLE `personnel`
  ADD PRIMARY KEY (`idPers`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `personnel`
--
ALTER TABLE `personnel`
  MODIFY `idPers` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
