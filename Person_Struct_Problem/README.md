[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- ABOUT THE PROJECT -->
## Despre proiect
<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Descrierea problemei</summary>
  <ol>
    <li>
    Va rugam sa realizati un program C (aplicatie C, in mod consola), care va citi dintr-un fisier de intrare  binar toate inregistarile si va genera un fisier de iesire de tip ASCII. 
Numele fisierelor de intrare si de iesire se vor citi din fisierul de configurare “testc.ini”, scris dupa formatul unui fisier de tip .ini. In acest fisier, in cadrul sectiunii “testc”; cheia, in cazul fisierului de intare, este “in”, iar in cazul celui de iesire este “out”. 
Fiecarei inregistari din fisierul de intrare ii va corespunde o linie in fisierul de iesire.
Structura inregistrarilor din fisierul de intrare este definita in fisierul “Person.h”.
Structura liniilor fisierului de iesire, in functie de tipul inregistrarii din fisierul de intrare, este urmatoarea:

Inregistare de tip 1 (date personale)


| Camp | Pozitie | Nr. Caractere | Obs |
| :--- | :---:   |    :---:      | ---:|
| PersonID   | 1     | 4	    |        |
| RecordType | 5     | 1      | Este 1 |
| LastName   | 6     | 30     |  |
| FirstName  | 36    | 30     |  |
| Birthdate  | 66    | 10     | Data in format, ZZ-LL-AAAA |
| Gender | 76     | 1      | Sexul: M – masculin; F – feminin. |
| CR/LF  | 77     | 2      | Terminator linie |

Inregistare de tip 2 (date legate de domiciliu)


| Camp | Pozitie | Nr. Caractere | Obs |
| :--- | :---:   |    :---:      | ---:|
| PersonID   | 1     | 4	    |        |
| RecordType | 5     | 1      | Este 2 |
| Street     | 6     | 30     |        |
| City       | 36    | 30     |        | 
| Country    | 66    | 10     |        |
| Phone      | 96    | 15     |        |
| E-mail     | 111   | 30     |        |
| CR/LF      | 77    | 2      | Terminator linie |

Inregistare de tip 3 (date legate de locul de munca)

| Camp | Pozitie | Nr. Caractere | Obs |
| :--- | :---:   |    :---:      | ---:|
| PersonID   | 1     | 4	    |        |
| RecordType | 5     | 1      | Este 2 |
| Company    | 6     | 30     |        |
| Street     | 36    | 30     |        |
| City       | 66    | 30     |        | 
| Country    | 96    | 30     |        |
| Phone      | 126   | 15     |        |
| Fax        | 141   | 15     |        |
| E-mail     | 156   | 30     |        |
| CR/LF      | 186   | 2      | Terminator linie |

Nota: Campurile unei linii din fisierul de iesire sunt dispuse in coloane de lungime fixa si corespund cu campurile inregistrarii corespunzatoare din fisierul de intrare (dupa scructura descrisa in fisierul Person.h).
  </li>
  </ol>
</details>


### Construit în

* [C](https://www.cplusplus.com/)

