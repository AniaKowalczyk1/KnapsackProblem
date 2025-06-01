Opis projektu
Projekt implementuje klasyczne rozwiązanie problemu plecaka 0/1 (Knapsack problem) za pomocą metody Branch and Bound. Celem jest znalezienie optymalnego zestawu przedmiotów o określonej wadze i wartości (proficie), tak aby maksymalizować łączny profit, nie przekraczając ustalonego limitu wagi plecaka.

Jak działa program?
Program przyjmuje listę przedmiotów, zdefiniowanych przez:
indeks,
wartość (profit),
wagę,
stosunek wartości do wagi,
oraz flagę aktywności.

Na podstawie tych danych oraz limitu maksymalnej wagi plecaka (W) tworzy drzewo decyzji (węzłów), w którym każdy węzeł reprezentuje decyzję o wyborze lub odrzuceniu konkretnego przedmiotu.
Wykorzystuje metodę Branch and Bound, czyli:
rekurencyjnie bada kolejne możliwe zestawy przedmiotów,
wykorzystuje granice górne (upper bound) do odrzucania nieobiecujących rozgałęzień drzewa,
dzięki temu znacząco zmniejsza liczbę przeszukiwanych kombinacji i przyspiesza znalezienie rozwiązania optymalnego.

Wynik — maksymalny uzyskany profit — jest zapisywany do pliku tekstowego oraz wyświetlany na ekranie.
