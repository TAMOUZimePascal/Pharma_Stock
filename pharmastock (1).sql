-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : mar. 04 juin 2024 à 11:40
-- Version du serveur : 10.4.28-MariaDB
-- Version de PHP : 8.2.4

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
-- Structure de la table `approvisionnement`
--

CREATE TABLE `approvisionnement` (
  `idAp` int(5) NOT NULL,
  `codeAp` varchar(50) NOT NULL,
  `dateAp` date NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `approvisionnement`
--

INSERT INTO `approvisionnement` (`idAp`, `codeAp`, `dateAp`, `codePers`) VALUES
(8, 'APP01', '2024-05-15', 'Bjr'),
(9, 'APP09', '2024-05-15', 'Bjr'),
(14, 'APP10', '2024-05-21', 'Bjr'),
(15, 'APP15', '2024-05-22', 'Bjr'),
(16, 'APP16', '2024-05-22', 'Bjr'),
(17, 'APP17', '2024-05-22', 'Bjr'),
(18, 'APP18', '2024-05-22', 'Bjr'),
(19, 'APP19', '2024-05-22', 'Bjr'),
(20, 'APP20', '2024-05-24', 'P002'),
(28, 'APP21', '2024-05-25', 'P002');

-- --------------------------------------------------------

--
-- Structure de la table `approvisionner`
--

CREATE TABLE `approvisionner` (
  `codeAp` varchar(50) NOT NULL,
  `codePro` varchar(50) NOT NULL,
  `qteApprovisionne` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `approvisionner`
--

INSERT INTO `approvisionner` (`codeAp`, `codePro`, `qteApprovisionne`) VALUES
('APP10', 'PAR001', 0),
('APP15', 'PAR0011', 0),
('APP16', 'VIT0013', 0),
('APP17', 'VIT0013', 0),
('APP17', 'PAR001', 0),
('APP18', 'PAR0011', 0),
('APP18', 'VIT0013', 0),
('APP19', 'VIT0013', 0),
('APP19', 'PAR001', 0),
('APP20', 'ZIK0012', 0),
('APP20', 'PAR001', 0),
('APP20', 'VIT0013', 0),
('APP21', 'ZIK0012', 5);

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE `client` (
  `idCli` int(5) NOT NULL,
  `codeCli` varchar(50) NOT NULL,
  `nomCli` varchar(255) NOT NULL,
  `telephoneCli` varchar(30) NOT NULL,
  `mailCli` varchar(50) NOT NULL,
  `adresseCli` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `client`
--

INSERT INTO `client` (`idCli`, `codeCli`, `nomCli`, `telephoneCli`, `mailCli`, `adresseCli`) VALUES
(1, '00001', 'PJC Jean Coutu', '+1 819 563 1212', 'pharmacypjc@jeancoutu.ca', '445 Rue King E, Sherbrooke, QC J1G 1B6, Canada'),
(2, '00002', 'Uniprix S. Grégoire et D. Thibaut - Pharmacie affi', '+1 819 823 1515', 'contact@uniprix.ca', '330 Rue des Erables, Sherbrooke, QC J1L 2A9, Canada'),
(6, '00003', 'Pharmacie Desjardins', '+1 819 342 6712', 'contact@desjardins.ca', '3768 Rue de l\'impériale, Sherbrooke, QC ');

-- --------------------------------------------------------

--
-- Structure de la table `commande`
--

CREATE TABLE `commande` (
  `idCom` int(5) NOT NULL,
  `codeCom` varchar(255) NOT NULL,
  `dateCom` date NOT NULL,
  `codeF` varchar(30) NOT NULL,
  `codePers` varchar(30) NOT NULL,
  `description` varchar(255) NOT NULL,
  `quantite` int(11) NOT NULL,
  `prixAchat` double NOT NULL,
  `totalPrixAchat` double NOT NULL,
  `codePro` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `commande`
--

INSERT INTO `commande` (`idCom`, `codeCom`, `dateCom`, `codeF`, `codePers`, `description`, `quantite`, `prixAchat`, `totalPrixAchat`, `codePro`) VALUES
(1, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Paracetamol 500mg', 50, 0, 0, ''),
(2, 'COM2024-077', '2024-05-24', '00001', 'P003', 'CAC100 éfféversant ', 34, 0, 0, ''),
(3, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Sérum glucosé', 30, 0, 0, ''),
(4, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Amapine-10 Comprimé', 25, 0, 0, ''),
(5, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Paracetamol 500mg', 50, 0, 0, ''),
(6, 'COM2024-077', '2024-05-24', '00001', 'P003', 'CAC100 éfféversant ', 34, 0, 0, ''),
(7, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Sérum glucosé', 30, 0, 0, ''),
(8, 'COM2024-077', '2024-05-24', '00001', 'P003', 'Amapine-10 Comprimé', 25, 0, 0, ''),
(9, 'COM2024-162', '2024-05-24', '00001', 'P003', 'Doliprane comprimé', 38, 0, 0, ''),
(10, 'COM2024-162', '2024-05-24', '00001', 'P003', 'EFFERALGAN', 15, 0, 0, ''),
(11, 'COM2024-162', '2024-05-24', '00001', 'P003', 'IMODIUM', 25, 0, 0, ''),
(12, 'COM2024-251', '2024-05-24', '00002', 'P003', 'Para Sérum', 10, 0, 0, ''),
(13, 'COM2024-125', '2024-05-24', '00001', 'P003', 'TrèsBonComprimés', 23, 0, 0, ''),
(14, 'COM2024-125', '2024-05-24', '00001', 'P003', 'LEVOTHYROX', 4, 0, 0, '');

-- --------------------------------------------------------

--
-- Structure de la table `contenir`
--

CREATE TABLE `contenir` (
  `codePro` varchar(30) NOT NULL,
  `codeF` varchar(30) NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Structure de la table `fournisseur`
--

CREATE TABLE `fournisseur` (
  `idF` int(5) NOT NULL,
  `codeF` varchar(30) NOT NULL,
  `contact` varchar(15) NOT NULL,
  `nomF` varchar(50) NOT NULL,
  `mail` varchar(30) NOT NULL,
  `adresse` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `fournisseur`
--

INSERT INTO `fournisseur` (`idF`, `codeF`, `contact`, `nomF`, `mail`, `adresse`) VALUES
(1, '00001', '+1 45 567  354', 'PHARMA LTD', 'contact@pharmaltd.ca', 'Sherbrooke rue de l\'impériale'),
(3, '00002', '+1 45 634 456 ', 'LABORATOIRE JEAN CLAUDE', 'jeanclaude@laboratoire.ca', 'Sherbrooke 74365 Bd de l\'unive');

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
  `password` varchar(255) DEFAULT NULL,
  `rolePers` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `personnel`
--

INSERT INTO `personnel` (`idPers`, `codePers`, `nomPers`, `prenomPers`, `contactPers`, `mailPers`, `password`, `rolePers`) VALUES
(1, 'P001', 'BEN', 'LUC', '3455678', 'luc@gmail.com', NULL, 'Responsable de vente'),
(2, 'P002', 'PEN', 'PIN', '1256789', 'pin@gmail.com', NULL, 'Responsable de stock');

-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE `produit` (
  `idPro` int(5) NOT NULL,
  `codePro` varchar(30) NOT NULL,
  `nomPro` varchar(50) NOT NULL,
  `dosage` varchar(50) NOT NULL,
  `caracteristique` varchar(255) NOT NULL,
  `prixUnit` float NOT NULL,
  `nbrePieces` int(11) NOT NULL,
  `qtePro` int(15) NOT NULL,
  `dateExpiration` date DEFAULT NULL,
  `codeType` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `produit`
--

INSERT INTO `produit` (`idPro`, `codePro`, `nomPro`, `dosage`, `caracteristique`, `prixUnit`, `nbrePieces`, `qtePro`, `dateExpiration`, `codeType`) VALUES
(9, 'PAR001', 'paracétamol', '250mg', '5', 4000, 12, 2, '2024-05-30', 'COM001'),
(10, 'PAR0010', 'paracétamol', '250mg', '', 4000, 12, 0, '2024-05-25', 'COM0021'),
(11, 'PAR0011', 'paracétamol', '500mg', '2', 4000, 12, 0, '2024-05-25', 'COM0022'),
(12, 'ZIK0012', 'zikkar', '250mg', '5', 4000, 15, 0, '2024-05-25', 'COM0023'),
(13, 'VIT0013', 'VitamineC', '500ml', '8', 10000, 30, 2, '2024-05-29', 'SIR0024');

-- --------------------------------------------------------

--
-- Structure de la table `responsable_operation`
--

CREATE TABLE `responsable_operation` (
  `idPers` int(5) NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Structure de la table `responsable_stock`
--

CREATE TABLE `responsable_stock` (
  `idPers` int(5) NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Structure de la table `responsable_vente`
--

CREATE TABLE `responsable_vente` (
  `idPers` int(5) NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Structure de la table `transactions`
--

CREATE TABLE `transactions` (
  `id` int(11) NOT NULL,
  `codeTrans` varchar(30) NOT NULL,
  `date` datetime NOT NULL DEFAULT current_timestamp(),
  `action` varchar(255) DEFAULT NULL,
  `motif` text DEFAULT NULL,
  `depositaire` varchar(255) DEFAULT NULL,
  `moyenPaiement` varchar(255) NOT NULL,
  `montant` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Déchargement des données de la table `transactions`
--

INSERT INTO `transactions` (`id`, `codeTrans`, `date`, `action`, `motif`, `depositaire`, `moyenPaiement`, `montant`) VALUES
(1, 'T00001', '2024-05-21 00:00:00', 'Encaissement', 'Vente de la joiurnée', 'Caissière ', 'Espèces', 305000),
(2, 'T00002', '2000-01-01 00:00:00', 'Encaissement', 'Vente', 'Caisière', 'Chèque', 10000),
(5, 'T00005', '2000-01-01 00:00:00', 'Encaissement', 'Vente', 'caissière', 'Espèces', 10000),
(6, 'T00006', '2000-01-01 00:00:00', 'Décaissement', 'Réaprovisionnement', 'Responsable des opération', 'Carte Bancaire', 150500);

-- --------------------------------------------------------

--
-- Structure de la table `typeproduit`
--

CREATE TABLE `typeproduit` (
  `idType` int(5) NOT NULL,
  `codeType` varchar(15) NOT NULL,
  `typePro` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `typeproduit`
--

INSERT INTO `typeproduit` (`idType`, `codeType`, `typePro`) VALUES
(20, 'COM001', 'Comprimé'),
(21, 'COM0021', 'Comprimé'),
(22, 'COM0022', 'Comprimé'),
(23, 'COM0023', 'Comprimé'),
(24, 'SIR0024', 'Siro');

-- --------------------------------------------------------

--
-- Structure de la table `vendre`
--

CREATE TABLE `vendre` (
  `codeV` varchar(50) NOT NULL,
  `codePro` varchar(50) NOT NULL,
  `qteVendue` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `vendre`
--

INSERT INTO `vendre` (`codeV`, `codePro`, `qteVendue`) VALUES
('FA0015', 'PAR0011', 2),
('FA0015', 'PAR001', 7),
('FA0020', 'PAR0011', 7),
('FA0020', 'VIT0013', 9),
('FA0021', 'PAR0011', 5),
('FA0021', 'VIT0013', 5),
('FA0023', 'PAR001', 0),
('FA0023', 'VIT0013', 0);

-- --------------------------------------------------------

--
-- Structure de la table `vente`
--

CREATE TABLE `vente` (
  `idVente` int(5) NOT NULL,
  `codeV` varchar(30) NOT NULL,
  `montantV` float NOT NULL,
  `dateV` date NOT NULL,
  `statut` varchar(255) NOT NULL,
  `codeCli` varchar(30) NOT NULL,
  `codePers` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `vente`
--

INSERT INTO `vente` (`idVente`, `codeV`, `montantV`, `dateV`, `statut`, `codeCli`, `codePers`) VALUES
(5, 'F001', 8000, '2024-05-24', '', '00001', 'P001'),
(14, 'FA006', 12000, '2024-04-24', '', '00004', 'P001'),
(19, 'FA0015', 8000, '2024-05-25', '', '00001', 'P001'),
(20, 'FA0020', 24000, '2024-06-25', '', '00002', 'P001'),
(21, 'FA0021', 14000, '2024-05-26', '', '00003', 'P001'),
(22, 'FA0022', 0, '2024-05-30', '', '00002', 'P001'),
(24, 'FA0023', 38000, '2024-05-30', '', '00002', 'P001'),
(25, 'FA0025', 10000, '2024-05-30', '', '00002', 'P001'),
(26, 'FA0026', 14000, '2024-05-30', '', '00002', 'P001');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `approvisionnement`
--
ALTER TABLE `approvisionnement`
  ADD PRIMARY KEY (`idAp`);

--
-- Index pour la table `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`idCli`);

--
-- Index pour la table `commande`
--
ALTER TABLE `commande`
  ADD PRIMARY KEY (`idCom`);

--
-- Index pour la table `fournisseur`
--
ALTER TABLE `fournisseur`
  ADD PRIMARY KEY (`idF`);

--
-- Index pour la table `personnel`
--
ALTER TABLE `personnel`
  ADD PRIMARY KEY (`idPers`);

--
-- Index pour la table `produit`
--
ALTER TABLE `produit`
  ADD PRIMARY KEY (`idPro`);

--
-- Index pour la table `responsable_operation`
--
ALTER TABLE `responsable_operation`
  ADD PRIMARY KEY (`idPers`);

--
-- Index pour la table `responsable_stock`
--
ALTER TABLE `responsable_stock`
  ADD PRIMARY KEY (`idPers`);

--
-- Index pour la table `responsable_vente`
--
ALTER TABLE `responsable_vente`
  ADD KEY `idPers` (`idPers`);

--
-- Index pour la table `transactions`
--
ALTER TABLE `transactions`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `typeproduit`
--
ALTER TABLE `typeproduit`
  ADD PRIMARY KEY (`idType`);

--
-- Index pour la table `vente`
--
ALTER TABLE `vente`
  ADD PRIMARY KEY (`idVente`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `approvisionnement`
--
ALTER TABLE `approvisionnement`
  MODIFY `idAp` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT pour la table `client`
--
ALTER TABLE `client`
  MODIFY `idCli` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT pour la table `commande`
--
ALTER TABLE `commande`
  MODIFY `idCom` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT pour la table `fournisseur`
--
ALTER TABLE `fournisseur`
  MODIFY `idF` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT pour la table `personnel`
--
ALTER TABLE `personnel`
  MODIFY `idPers` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `produit`
--
ALTER TABLE `produit`
  MODIFY `idPro` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT pour la table `transactions`
--
ALTER TABLE `transactions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `typeproduit`
--
ALTER TABLE `typeproduit`
  MODIFY `idType` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- AUTO_INCREMENT pour la table `vente`
--
ALTER TABLE `vente`
  MODIFY `idVente` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `responsable_operation`
--
ALTER TABLE `responsable_operation`
  ADD CONSTRAINT `responsable_operation_ibfk_1` FOREIGN KEY (`idPers`) REFERENCES `personnel` (`idPers`);

--
-- Contraintes pour la table `responsable_stock`
--
ALTER TABLE `responsable_stock`
  ADD CONSTRAINT `responsable_stock_ibfk_1` FOREIGN KEY (`idPers`) REFERENCES `personnel` (`idPers`);

--
-- Contraintes pour la table `responsable_vente`
--
ALTER TABLE `responsable_vente`
  ADD CONSTRAINT `idPers` FOREIGN KEY (`idPers`) REFERENCES `personnel` (`idPers`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
