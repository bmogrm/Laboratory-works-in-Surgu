(defun lins (ls)
   (let* ((focusDis (car ls))
          (disPic (cadr ls))
          (disObj (/ (* focusDis disPic)
                     (- disPic focusDis))))
     (write "Расстояние от линзы до предмета = ")
     (write disObj)
     (cond
      ((= disObj (* 2 focusDis)) "Изображение: действительное, перевернутое")
      ((> disObj (* 2 focusDis)) "Изображение: действительное, перевернутое, уменьшенное")
      ((and (< disObj (* 2 focusDis))
            (> disObj focusDis)) "Изображение: увеличенное, перевернутое, действительное")
      ((< disObj focusDis) "Изображение: увеличенное, прямое, мнимое")
      (t "Изображения нет"))))
(lins '(10 22))

(defun lins (ls)
   (let* ((focusDis (car ls))
          (disPic (cadr ls))
          (disObj (/ (* focusDis disPic)
                     (- disPic focusDis))))
     (prin1 "Расстояние от линзы до предмета = ")
     (prin1 disObj)
     (if (= disObj (* 2 focusDis)) "Изображение: действительное, перевернутое"
       (if (> disObj (* 2 focusDis)) "Изображение: действительное, перевернутое, уменьшенное"
         (if (and (< disObj (* 2 focusDis))
                  (> disObj focusDis)) "Изображение: увеличенное, перевернутое, действительное"
           (if (< disObj focusDis) "Изображение: увеличенное, прямое, мнимое" "Изображения нет"))))))
(lins '(10 22))