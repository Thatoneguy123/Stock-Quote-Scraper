CREATE USER '<name>'@'localhost' IDENTIFIED BY '<password>';

CREATE DATABASE stock_database;

CREATE TABLE `stock_database`.`stock` (
  `sid` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  `ticker` VARCHAR(7)  NOT NULL,
  `company` VARCHAR(40)  NOT NULL,
  PRIMARY KEY (`sid`)
)
ENGINE = InnoDB
AUTO_INCREMENT = 1;

CREATE TABLE `stock_database`.`price` (
  `Date` DATETIME  NOT NULL,
  `sid` BIGINT UNSIGNED NOT NULL,
  `close` DOUBLE  NOT NULL,
  `open` DOUBLE  NOT NULL,
  `high` DOUBLE  NOT NULL,
  `low` DOUBLE  NOT NULL,
  `volume` BIGINT UNSIGNED NOT NULL,
  PRIMARY KEY (`Date`, `sid`)
)
ENGINE = InnoDB;

GRANT SELECT, INSERT, UPDATE, DELETE ON stock_database.* TO '<name>'@'localhost';



