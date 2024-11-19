-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : sam. 25 mai 2024 à 12:13
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
-- Structure de la table `vendre`
--

CREATE TABLE `vendre` (
  `codeVente` varchar(50) NOT NULL,
  `codePro` varchar(50) NOT NULL,
  `qteVendue` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `vendre`
--

INSERT INTO `vendre` (`codeVente`, `codePro`, `qteVendue`) VALUES
('FA0015', 'PAR0011', 0),
('FA0015', 'PAR001', 0),
('FA0020', 'PAR0011', 0),
('FA0020', 'VIT0013', 0),
('FA0021', 'PAR0011', 0),
('FA0021', 'VIT0013', 0);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
