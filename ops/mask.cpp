#include <cstdio>

struct Mask{
    bool lu : 1;
    bool cu : 1;
    bool ru : 1;

    bool lc : 1;
    bool rc : 1;

    bool ld : 1;
    bool cd : 1;
    bool rd : 1;

    constexpr inline unsigned char operator()() const noexcept{
        return *const_cast<unsigned char *>(reinterpret_cast<const unsigned char *>(this));
    }

    constexpr inline operator unsigned char() const noexcept{
        return operator()();
    }

    constexpr inline Mask operator |(const Mask &other) const noexcept{
        unsigned char res = operator()() | other.operator()();
        return *reinterpret_cast<Mask *>(&res);
    }

    constexpr inline Mask operator &(const Mask &other) const noexcept{
        unsigned char res = operator()() & other.operator()();
        return *reinterpret_cast<Mask *>(&res);
    }

    constexpr inline Mask operator ~() const noexcept{
        unsigned char res = ~operator()();
        return *reinterpret_cast<Mask *>(&res);
    }
};

static constexpr const Mask
    m_lu{true},
    m_cu{false, true},
    m_ru{false, false, true},

    m_lc{false, false, false, true},
    m_rc{false, false, false, false, true},

    m_ld{false, false, false, false, false, true},
    m_cd{false, false, false, false, false, false, true},
    m_rd{false, false, false, false, false, false, false, true};

int main(){
    printf("Size of Mask: %d.\n", sizeof(Mask));
    printf("%d, %d, %d.\n", m_lu, m_cu, m_ru);
    printf("%d.\n", m_lu | m_cu);
    printf("%d.\n", m_cu & (m_ru | m_cu));
    printf("%d.\n", m_ru & ~m_lc);

    unsigned char lu = m_lu;
    return lu == 1 ? 0 : 1;
}
