# Datenstrukturen

## Klasse `Hashtable`
Verwaltet die Hashtable und alle Methoden, welche diese Hashtable modifizieren. Beinhaltet die Hashtabelle selbst als Array von `Stock` in welcher Pointer für alle Aktien gespeichert werden. Das einzigartige Symbol jeder Aktie soll bestimmen, wo die Aktie abgespeichert wird.

## Klasse `Stock`
Beinhaltet die Klasse Stock (Aktie), welche durch die einzigartige Bezeichung Symbol (Kürzel der Aktie) identifiziert wird. Stock importiert die Klasse `Stockday` und speichert ein Array, welche die Daten für die letzten 30 Tage festhält. Außerdem werden Methoden implementiert, um ein Objekt der Klasse zu modifizieren oder auszugeben.
 
 ## Klasse `Stockday`
 Bildet einen Tag eines Stocks (Aktie). Dort werden alle Daten für einen Tag der Kursdaten einer Aktie gespeichert und die Methoden, um diese Daten zu importieren.

# Protokoll

## Hashfunktion
Das Programm liest den Kürzel der einzugebenen Aktie ein und generiert daraus eine *einzigartige ID*, welche für die Verarbeitung zu einem gültigen Index der Hashtabelle benutzt wird. Wie wird bei der **Generierung der ID** vorgegangen?

1. Jeder char `char` wird in seinen ASCII-Wert als `int` umgerechnet.
2. Jedes `int` wird in einen `string` umgewandelt.
3. Jeder `string` wird aneinander gehängt.
4. Der gesamte `string` wird wieder in ein `int` umgewandelt.

Diese ID wird verwendet, um einen **Index zu errechnen**.

1. Es wird eine `int sondierung` berechnet, falls die Hashfunktion schonmal aufgerufen wurde (quadratisch). Dies geschieht mithilfe eines optionalen Paremeter `int steps` welcher standartmäßig `0` entspricht, aber mit belieben auch per Argument im Funktionsaufruf verändert werden kann.
2. Die ID der Aktie wird mit der Sondierung addiert und mit dem Modul der Größte der Hashtabelle verrechnet.

## Kollisionserkennung

### Einfügen
Da die Hashtabelle ein **Array von Pointern** auf die Klasse `Stock` ist, kann beim einfügen, löschen und suchen die Tabelle daraufhin untersucht werden, ob der Wert am untersuchten Index `NULL` ist. 

### Suchen (& Löschen)
Gesucht wird über die Eingabe des Kürzels. Daraus wird schließlich die einzigartige ID gebildet und der selbe Prozess durchgangen, wie als würde man die Aktie einfügen (Hashfunktion). Der Unterschied liegt darin, dass bei jeder Kollision mit einer schon existierenden Aktie überprüft wird, ob die IDs die selben sind. Abbruchbedingung ist hierbei, dass die gesamte Tabelle durchsucht wurde. Wird nichst gefunden, gibt die Methode einen Index zurück, der größer als die Hashtabelle ist, was das Programm als Error abfängt und eine Fehlermeldung ausgibt, dass die gesuchte Aktie nicht gefunden wurde.

Sobald eine Kollision festgelesst wird, wird die Hashfunktion ein weiteres Mal aufgerufen, diesmal jedoch mit einem **weiteren Parameter**, genauer gesagt einem `int steps`, welcher der Hash-Funktion übermittelt, dass nun schon x Versuche gebraucht wurden, um einen gültigen Index zu berechnen. Diese Variable hilft auch dabei, eine **Abbruchbedingung** zu implementieren, falls die Algorithmen die gesamte Hashtabelle durchsuchen müssten. 

## Verwaltung der Kursdaten

Die Kursdaten werden in einem Array der Klasse `Stockday` abgespeichert. `Stockday` bezeichnet einen einzigen Tag einer Aktie und beinhaltet dem entsprechend alle Variablen, die dafür relevant sind. 

### Importieren
Mit der Eingabe des Kürzels der Aktie wird im Ordner der ausführbaren Datei nach einer gleichnamigen .csv-Datei gesucht. Folglich wird die Datei per Zeile eingelesen und pro Zeile die Methode `inputData()` der Klasse `Stockday` aufgerufen, welche die Zeile als `string` einliest und die Werte den zugehörigen Variablen zuweist.

### Grafik zeichnen
Nachdem die Aktie mit einer erfolgreichen Suche zurückgegeben wird. Werden die **maximalen und minimalen Werte** des Aktienkurses benutzt, um eine darzustellenden Spanne `double spanne` zu berechnen. Damit wird verhindert, dass kleine Kursschwankungen bei stabilen Aktienkursen so gut wie nicht erkennbar sind.
Die Darstellung geschieht über ASCII-Charaktere (je nach OS unterschiedlich), welchen abhängig von der Größe der dazustellenden Spanne ein anderes Gewicht gegeben wird.

### Speichern

### Laden

## Löschalgorithmus

Das wichtigste hierbei war, dass man die Aktie mit `delete` ganz aus dem Speicher nimmt und in der Hashtabelle, am dem entsprechenden Index wieder den Wert `NULL` einsetzt, damit beim nächsten Einfügen die Kollisionsbehandlung nicht verfälscht wird. Der vorangegangene Prozess ist ein schlichtes Aufrufen der `int search(int &stockID)`-Methode, welche einen gültigen Index zurückliefert oder einen Index welcher größer ist, als die Hashtabelle und dem Programm damit signalisiert, dass nichts gefunden wurde.

# Aufwandsabschätzung

## Hashtabelle
* Einfügen
- O(1) Best Case
- O(N) Worst Case

* Suchen
- O(1) Best Case
- O(N) Worst Case

* Löschen
- O(1) Best Case
- O(N) Worst Case


## Array
* Einfügen
- O(N) Best Case
- O(N) Worst Case

* Suchen
- O(N) Best Case
- O(N) Worst Case

* Löschen
- O(N) Best Case
- O(N) Worst Case


## Listen
* Einfügen
- O(1) Best Case
- O(1) Worst Case

* Suchen
- O(N) Best Case
- O(N) Worst Case

* Löschen
- O(1) Best Case
- O(N) Worst Case
