;; .emacs
(setq ansi-color-for-comint-mode t)
(customize-group 'ansi-colors)
(kill-this-buffer)              

;; Don't display menu bar. Type M-x menu-bar-mode to display it
(menu-bar-mode '-1)
;; Don't display tool bar. Type M-x tool-bar-mode to display it
(if (not (equal (getenv "HOSTTYPE") "sparc"))
    (tool-bar-mode '-1))

(defun linux-c-mode ()
	"C mode with adjusted defaults for use with the Linux kernel."
	(interactive)
	(c-mode)
	(c-set-style "K&R")
	(setq tab-width 8)
	(setq indent-tabs-mode t)
	(setq c-basic-offset 8)
)

(defun	my-c-mode ()
	"C mode with adjusted defaults for use with the C sources."
	(interactive)
	(c-mode)
	(c-set-style "K&R")
	(setq tab-width 4)
	(setq indent-tabs-mode t)
	(setq c-basic-offset 4)
)

(defun	my-c++-mode ()
	"C++ mode with adjusted defaults for use with the C++ sources."
	(interactive)
	(c++-mode)
	(c-set-style "K&R")
	(setq tab-width 4)
	(setq indent-tabs-mode t)
	(setq c-basic-offset 4)
)

(defun	my-asm-mode ()
	"ASM mode with adjusted defaults for use with the asm sources."
	(interactive)
	(asm-mode)
	(setq tab-width 8)
	(setq indent-tabs-mode t)
	(setq c-basic-offset 8)
)

(setq auto-mode-alist (cons '(".*\\.\\(inl$\\|cxx$\\|hxx$\\|cpp$\\|hpp$\\)" .
			my-c++-mode) auto-mode-alist))
(setq auto-mode-alist (cons '(".*\\.\\(inc$\\|[Ss]$\\)" .
			my-asm-mode) auto-mode-alist))
(setq auto-mode-alist (cons '(".*\\.\\(inl$\\|c$\\|h$\\)" .
			my-c-mode) auto-mode-alist))
(setq auto-mode-alist (cons '(".*/*kernel.*/+.*\\.[ch]$" .
			linux-c-mode) auto-mode-alist))

(setq witch-function-mode t)
(which-func-mode)

;; This maps edit keys to standard Windows keystokes. It requires the
;; library cua-mode.el from Kim Storm at the following URL:
(load "~/cua-mode.el")
(CUA-mode t)


;; Set foreground and background. black or dimgrey may be choosed
(set-foreground-color "white")
(set-background-color "gray11")
;set-background-color "CornflowerBlue")
;(set-background-color "DarkSlateBlue")
;(set-background-color "MidnightBlue")
;(set-background-color "Black")

;; Set the mouse and cursor color
(set-mouse-color "yellow")
(set-cursor-color "red")

(setq Man-overstrike-face 'info-node)
(setq Man-underline-face 'info-xref)

(shell)
(rename-buffer "aaaa-shell")
(shell)
(rename-buffer "bbbb-shell")
(shell)
(rename-buffer "cccc-shell")
(shell)
(rename-buffer "dddd-shell")
(shell)
(rename-buffer "eeee-shell")
(shell)
(rename-buffer "ffff-shell")
(shell)
(rename-buffer "make-shell")
(shell)
(rename-buffer "work-shell")

(show-paren-mode)
(global-auto-revert-mode)

;;; uncomment this line to disable loading of "default.el" at startup
;;(setq inhibit-default-init t)

;; turn on font-lock mode
(when (fboundp 'global-font-lock-mode)
  (global-font-lock-mode t))

;; enable visual feedback on selections
(setq transient-mark-mode t)
(setq line-move-visual nil)

;; default to better frame titles
(setq frame-title-format
      (concat  "%b - emacs@" system-name))

(add-hook 'comint-output-filter-functions
	'comint-watch-for-password-prompt)

(setq display-time-24hr-format t)
(setq display-time-day-and-date nil)
(display-time)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;(setq column-number-mode t)
(global-linum-mode t)
(setq x-select-enable-clipboard t)

;;yk--quick start
(setq inhibit-startup-message t)

;;high line
;(require 'hl-line)
;(global-hl-line-mode t)

;;tab
;(require 'tabbar)
;(tabbar-mode)
;(global-set-key (kbd "M-[") 'tabbar-backward-group)
;(global-set-key (kbd "M-]") 'tabbar-forward-group)
;(global-set-key (kbd "M-p") 'tabbar-backward-tab)
;(global-set-key (kbd "M-n") 'tabbar-forward-tab)

(column-number-mode t)

(setq make-backup-files nil)

(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(auto-compression-mode t nil (jka-compr))
 '(case-fold-search t)
 '(column-number-mode t)
 '(cua-mode t nil (cua-base))
 '(current-language-environment "UTF-8")
 '(default-input-method "rfc1345")
 '(display-time-mode t)
 '(ecb-layout-window-sizes nil)
 '(ecb-options-version "2.40")
 '(ecb-primary-secondary-mouse-buttons (quote mouse-1--mouse-2))
 '(global-font-lock-mode t nil (font-lock))
 '(next-line-add-newlines nil)
 '(scroll-bar-mode (quote right))
 '(semantic-c-dependency-system-include-path (quote ("/usr/include" "/home_a/mqru/work/kernel/kernel-3.0.8/include" "/home_a/mqru/work/kernel/kernel-3.0.8/arch/mips/include" "/home_a/mqru/work/kernel/kernel-3.0.8/arch/mips/xburst/soc-4780/include")))
 '(show-paren-mode t nil (paren))
 '(tool-bar-mode nil))

(setq ps-font-size 1)
(defun my-ps-print-buffer()
	(interactive)
	(message "  print ... ")
	(setq filename "~/tmp/1.ps")
	(ps-print-buffer-with-faces filename))

(global-set-key "\M-\C-p" 'my-ps-print-buffer)
(global-set-key "\C-g" 'goto-line)
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil :background "gray11" :foreground "white" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 161 :width normal :foundry "unknown" :family "DejaVu Sans Mono")))))

(customize-set-variable 'scroll-bar-mode 'right)

(setq inhibit-startup-message t)

(setq gnus-inhibit-startup-message t)

(setq scroll-margin 3 scroll-conservatively 10000)

(defun open-eshell-other-buffer ()
"Open eshell in other buffer"
(interactive)
(split-window-vertically)
(eshell))
(defun kill-shell ()
"Kill shell"
(interactive)
(kill-buffer-and-window))
(global-set-key [(f8)] 'open-eshell-other-buffer)
(global-set-key [C-f8] 'eshell)
(global-set-key [(f9)] 'kill-shell)

;; Load CEDET
(load-file "/home/user/.emacs.d/cedet/common/cedet.el")
;(global-ede-mode 1)
;; Enabling various SEMANTIC minor modes.  See semantic/INSTALL for more ideas.
;; Select one of the following:

;; * This enables the database and idle reparse engines
;(semantic-load-enable-minimum-features)

;; * This enables some tools useful for coding, such as summary mode
;;   imenu support, and the semantic navigator
;;(semantic-load-enable-code-helpers)

;; * This enables even more coding tools such as the nascent intellisense mode
;;   decoration mode, and stickyfunc mode (plus regular code helpers)
;;(semantic-load-enable-guady-code-helpers)

;; * This turns on which-func support (Plus all other code helpers)
;;(semantic-load-enable-excessive-code-helpers)

;; This turns on modes that aid in grammar writing and semantic tool
;; development.  It does not enable any other features such as code
;; helpers above.
;;(semantic-load-enable-semantic-debugging-helpers)

;;; gcc setup
;(require 'semantic-gcc)

;;; smart complitions setup
;;(require 'semantic-ia)


;(add-to-list 'load-path "~/.emacs.d/ecb-2.40")
(add-to-list 'load-path "~/.emacs.d/ecb-snap")
;(add-to-list 'load-path "~/.emacs-lisp/ecb/")

;;eg(add-to-list 'load-path "~/.emacs.d/ecb-2.32")
(require 'ecb)

;(set-default-font "Courier-12")
;(add-to-list 'default-frame-alist '(font . "Courier-12"))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  semantic
(require 'cc-mode)
;(define-key c-mode-base-map (kbd "\C-tab") 'semantic-ia-complete-symbol-menu)
;;(define-key c-mode-base-map [(control tab)] 'semantic-ia-complete-symbol-menu)
;;(define-key c-mode-base-map [(f7)] 'semantic-ia-fast-jump)
;;(define-key c-mode-base-map [(S-f7)] 'semantic-mrub-switch-tags)
;(define-key c-mode-base-map [(control tab)] 'ac-complete-semantic-raw)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;ecb

;(setq ecb-auto-activate t)
(setq ecb-tip-of-the-day nil)
(ecb-activate)
(ecb-hide-ecb-windows)

(global-set-key [M-left] 'windmove-left)

(global-set-key [M-right] 'windmove-right)

(global-set-key [M-up] 'windmove-up)

(global-set-key [M-down] 'windmove-down) 

(define-key global-map [f5] 'ecb-show-ecb-windows)
(define-key global-map [f6] 'ecb-hide-ecb-windows)


;(define-key global-map "/C-c1" 'ecb-maximize-window-directories)

;(define-key global-map "/C-c2" 'ecb-maximize-window-sources)

;(define-key global-map "/C-c3" 'ecb-maximize-window-methods)

;(define-key global-map "/C-c4" 'ecb-maximize-window-history)

;(define-key global-map "/C-c`" 'ecb-restore-default-window-sizes)
 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ecb layout
(ecb-layout-define "user-ecb-layout" right nil  
                   (ecb-set-directories-buffer)
                   (ecb-split-ver 0.3 t)  
                   (other-window 1)  
                   (ecb-set-sources-buffer)  
                   (ecb-split-ver 0.3 t)  
                   (other-window 1)  
                   (ecb-set-methods-buffer))  
  
(setq ecb-layout-name "user-ecb-layout")  
  
;; Disable buckets so that history buffer can display more entries  
;(setq ecb-history-make-buckets 'never)  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(load-file "/home/user/.emacs.d/cl-lib.el")
 
(add-to-list 'load-path "~/.emacs.d/yasnippet")
(require 'yasnippet)
(yas/load-directory "~/.emacs.d/yasnippet/snippets")
(yas-global-mode 1)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;(add-to-list 'load-path "/home/user/.emacs.d/auto-complete-1.3.1")
;(require 'auto-complete-config)
;(add-to-list 'ac-dictionary-directories "/home/user/.emacs.d/ac-dict")



(add-to-list 'load-path "~/.emacs.d/auto-complete")
(add-to-list 'load-path "~/.emacs.d/popup-el")
(require 'popup)
(require 'auto-complete)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/dict")
(setq ac-trigger-commands
      (cons 'backward-delete-char-untabify ac-trigger-commands))

(require 'auto-complete-config)
(setq ac-dwim t)
(setq ac-use-quick-help t)
;(setq ac-quick-help-delay 1.0)

;(ac-config-default)
;(setq-default ac-sources '(ac-source-semantic ac-source-yasnippet))
(set-default 'ac-sources
             '(ac-source-semantic ;;ac使用semantic的分析结果
	       ac-source-yasnippet
	       ac-source-abbrev
               ac-source-words-in-buffer
               ac-source-words-in-all-buffer
              ))
(setq ac-auto-start 3)
(global-auto-complete-mode)
;(require 'auto-complete-semantic nil t)
;(setq-default ac-sources '(ac-source-semantic))   
;(setq semantic-edits-verbose-flag nil)


;bootmark
(add-to-list 'load-path "~/.emacs.d/")
(require 'bm)
(global-set-key (kbd "<C-f2>") 'bm-toggle)
(global-set-key (kbd "<f2>")   'bm-next)
(global-set-key (kbd "<S-f2>") 'bm-previous)
(require 'highlight-parentheses)

(require 'highlight-symbol)
(global-set-key [(control f4)] 'highlight-symbol-at-point)
(global-set-key [f4] 'highlight-symbol-next)
(global-set-key [(shift f4)] 'highlight-symbol-prev)
(global-set-key [(meta f4)] 'highlight-symbol-prev)


;globl --gtags
(load-file "/home/user/.emacs.d/gtags.el")  
(add-hook 'c-mode-hook 
       '(lambda () 
         (gtags-mode 1))) 
  
(add-hook 'c++-mode-hook 
       '(lambda () 
         (gtags-mode 1))) 
  
(add-hook 'asm-mode-hook 
       '(lambda () 
         (gtags-mode 1)))

(add-hook 'gtags-mode-hook
  '(lambda ()
        ; Local customization (overwrite key mapping)
        (define-key gtags-mode-map "\C-f" 'scroll-up)
        (define-key gtags-mode-map "\C-b" 'scroll-down)
))
(add-hook 'gtags-select-mode-hook
  '(lambda ()
        (setq hl-line-face 'underline)
        (hl-line-mode 1)
))

(defun create-tags (/home/user/work/)
     "Create tags file."
     (interactive "DDirectory:/home/user/work")
     (eshell-command 
      (format "find %s -type f -name \"*.[ch]\" | etags -" dir-name)))

; Customization
(setq gtags-suggested-key-mapping t)
(setq gtags-auto-update t)

(server-start)

(put 'upcase-region 'disabled nil)

 (load "/usr/share/emacs/site-lisp/global/gtags.el")
 (autoload 'gtags-mode "gtags" "" t)  ;gtags-mode is true
 (global-set-key (kbd "M-.") 'gtags-find-tag)
 (global-set-key (kbd "M-,") 'gtags-find-rtag)
 (global-set-key (kbd "M-g M-f") 'gtags-find-file)
 (global-set-key (kbd "M-g M-s") 'gtags-find-symbol)
 (global-set-key (kbd "M-g M-u") 'gtags-update)
