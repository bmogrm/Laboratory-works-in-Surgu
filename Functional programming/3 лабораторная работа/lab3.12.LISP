(defun lins (ls)
   (let* ((focusDis (car ls))
          (disPic (cadr ls))
          (disObj (/ (* focusDis disPic)
                     (- disPic focusDis))))
     (write "���������� �� ����� �� �������� = ")
     (write disObj)
     (cond
      ((= disObj (* 2 focusDis)) "�����������: ��������������, ������������")
      ((> disObj (* 2 focusDis)) "�����������: ��������������, ������������, �����������")
      ((and (< disObj (* 2 focusDis))
            (> disObj focusDis)) "�����������: �����������, ������������, ��������������")
      ((< disObj focusDis) "�����������: �����������, ������, ������")
      (t "����������� ���"))))
(lins '(10 22))

(defun lins (ls)
   (let* ((focusDis (car ls))
          (disPic (cadr ls))
          (disObj (/ (* focusDis disPic)
                     (- disPic focusDis))))
     (prin1 "���������� �� ����� �� �������� = ")
     (prin1 disObj)
     (if (= disObj (* 2 focusDis)) "�����������: ��������������, ������������"
       (if (> disObj (* 2 focusDis)) "�����������: ��������������, ������������, �����������"
         (if (and (< disObj (* 2 focusDis))
                  (> disObj focusDis)) "�����������: �����������, ������������, ��������������"
           (if (< disObj focusDis) "�����������: �����������, ������, ������" "����������� ���"))))))
(lins '(10 22))